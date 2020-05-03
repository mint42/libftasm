#include "tester.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/wait.h>

void	zero_tests(struct s_test *tests)
{
	bzero(tests, MAX_TESTS * sizeof(struct s_test));
}

void	load_test(struct s_test *test, char *name, int (*func)(void))
{
	test->test_name = name;
	test->test_func = func;
}

static char		*handle_status(int status)
{
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			return ("\e[0;32mOK\e[m");
		else
			return ("\e[0;35mKO\e[m");
	}
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 10)
			return ("\e[0;31mBUS\e[m");
		else if (WTERMSIG(status) == 11)
			return ("\e[0;33mSEGV\e[m");
	}
	return ("UNK");
}

static char		*run_test(int (*test)(void))
{
	pid_t	new_pid;
	int		status;
	char	*ret;

	status = 0;
	new_pid = fork();
	if (new_pid < 0)
	{
		printf("fork failed\n");
	}
	else if (new_pid == 0)
	{
		status = test();
		exit(status);
	}
	else
	{
		wait(&status);
		ret = handle_status(status);
		return (ret);
	}
	return (0);
}

int				main(void)
{
	struct s_test_wrap	funcs[N_FUNCS];

	load_tests_ft_isascii(&(funcs[0]));
	load_tests_ft_isalnum(&(funcs[1]));
	load_tests_ft_isalpha(&(funcs[2]));
	load_tests_ft_isdigit(&(funcs[3]));
	load_tests_ft_strcmp(&(funcs[4]));
	load_tests_ft_strdup(&(funcs[5]));
	load_tests_ft_strcpy(&(funcs[6]));
//	load_tests_ft_strncpy(&(funcs[2]));
//	load_tests_ft_bzero(&(funcs[0]));
//	load_tests_ft_read(&(funcs[4]));
//	load_tests_ft_write(&(funcs[5]));

	for (int i = 0 ; i < N_FUNCS ; i++)
	{
		printf("--------------------------------------\n");
		printf("	%s\n", funcs[i].name);
		printf("--------------------------------------\n");
		for (int j = 0 ; j < funcs[i].n_tests ; j++)
		{
			printf("Test%2d: %-20s [%s]", j + 1, funcs[i].tests[j].test_name,
				run_test(funcs[i].tests[j].test_func));
			printf("\n");
		}
		printf("\n");
	}
	return (0);
}
