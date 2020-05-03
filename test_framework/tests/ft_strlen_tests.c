#include "libasm.h"
#include "tester.h"
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen_test_1(void)
{
	size_t	tst;
	size_t	sys;

	tst = _ft_strlen("Hello World!");
	sys = strlen("Hello World!");

	return ((tst == sys) ? 0 : 1);
}

int		ft_strlen_test_2(void)
{
	size_t	tst;
	size_t	sys;

	tst = _ft_strlen("");
	sys = strlen("");

	return ((tst == sys) ? 0 : 1);
}

int		ft_strlen_test_3(void)
{
	size_t	tst;
	size_t	sys;

	tst = _ft_strlen(NULL);
	sys = strlen(NULL);

	return ((tst == sys) ? 0 : 1);
}

int		ft_strlen_test_4(void)
{
	int		size;
	size_t	tst;
	size_t	sys;

	size = (rand() % 10000) + 10000;

	char	*str = malloc(size);

	for (int i = 0; i < size; i++)
	{
		str[i] = (rand() % 94) + 32;
	}
	str[size - 1] = '\0';

	tst = _ft_strlen(str);
	sys = strlen(str);
	if (str)
		free(str);
	return ((tst == sys) ? 0 : 1);
}

void	load_tests_ft_strlen(struct s_test_wrap *func)
{
	func->name = "FT_STRLEN";
	func->n_tests = 4;
	zero_tests(func->tests);
	load_test(&((func->tests)[0]), "Basic", ft_strlen_test_1);
	load_test(&((func->tests)[1]), "Empty", ft_strlen_test_2);
	load_test(&((func->tests)[2]), "NULL", ft_strlen_test_3);
	load_test(&((func->tests)[3]), "Long", ft_strlen_test_4);
}
