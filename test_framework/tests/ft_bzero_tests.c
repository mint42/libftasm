#include "libasm.h"
#include "tester.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_bzero_test_1(void)
{
	int		ret;
	char	tst[10] = "123456789";
	char	sys[10] = "123456789";

	ft_bzero(tst, 5);
	bzero(sys, 5);

	ret = (strcmp(tst, sys)) ? 1 : 0;
	return (ret);
}

int		ft_bzero_test_2(void)
{
	int		ret;
	char	*tst = malloc(10);
	char	*sys = malloc(10);

	tst = strcpy(tst, "123456789");
	sys = strcpy(sys, "123456789");

	ft_bzero(tst, 10);
	bzero(sys, 10);

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_bzero_test_3(void)
{
	int		ret;
	char	*tst = malloc(10);
	char	*sys = malloc(10);

	tst = strcpy(tst, "123456789");
	sys = strcpy(sys, "123456789");

	ft_bzero(tst, 11);
	bzero(sys, 11);

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_bzero_test_4(void)
{
	ft_bzero(NULL, 10);
	bzero(NULL, 10);

	return (1);
}

int		ft_bzero_test_5(void)
{
	int		ret;
	int		size;

	size = (rand() % 10000) + 10000;

	char	*src = malloc(size);
	char	*tst = malloc(size);
	char	*sys = malloc(size);

	for (int i = 0; i < size; i++)
	{
		src[i] = (rand() % 94) + 32;
		tst[i] = src[i];
		sys[i] = src[i];
	}
	src[size - 1] = '\0';
	tst[size - 1] = '\0';
	sys[size - 1] = '\0';

	tst = ft_strcpy(tst, src);
	sys = strcpy(sys, src);

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (src)
		free(src);
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

void	load_tests_ft_bzero(struct s_test_wrap *func)
{
	func->name = "FT_BZERO";
	func->n_tests = 5;
	zero_tests(func->tests);
	load_test(&((func->tests)[0]), "Basic", ft_bzero_test_1);
	load_test(&((func->tests)[1]), "Malloc", ft_bzero_test_2);
	load_test(&((func->tests)[2]), "Malloc Overwrite", ft_bzero_test_3);
	load_test(&((func->tests)[3]), "NULL", ft_bzero_test_4);
	load_test(&((func->tests)[4]), "Long", ft_bzero_test_5);
}
