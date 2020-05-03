#include "libasm.h"
#include "tester.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int		ft_strdup_test_1(void)
{
	int		ret;
	char	*tst;
	char	*sys;

	tst = _ft_strdup("Hello World!");
	sys = strdup("Hello World!");

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_strdup_test_2(void)
{
	int		ret;
	char	*tst;
	char	*sys;

	tst = _ft_strdup("");
	sys = strdup("");

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_strdup_test_3(void)
{
	int		ret;
	char	*tst;
	char	*sys;

	tst = _ft_strdup(NULL);
	sys = strdup(NULL);

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_strdup_test_4(void)
{
	int		ret;
	size_t	size;
	char	*src;
	char	*tst;
	char	*sys;

	size = (rand() % 10000) + 10000;

	for (int i = 0; i < size; i++)
	{
		src[i] = (rand() % 94) + 32;
	}
	src[size - 1] = '\0';

	tst = _ft_strdup(src);
	sys = strdup(src);

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

void	load_tests_ft_strdup(struct s_test_wrap *func)
{
	func->name = "FT_STRDUP";
	func->n_tests = 4;
	zero_tests(func->tests);
	load_test(&((func->tests)[0]), "Basic", ft_strdup_test_1);
	load_test(&((func->tests)[1]), "Empty", ft_strdup_test_2);
	load_test(&((func->tests)[2]), "NULL", ft_strdup_test_3);
	load_test(&((func->tests)[3]), "Long", ft_strdup_test_4);
}
