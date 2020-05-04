#include "libasm.h"
#include "tester.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strcpy_test_1(void)
{
	int		ret;
	char	*tst = malloc(13);
	char	*sys = malloc(13);

	tst = ft_strcpy(tst, "Hello World!");
	sys = strcpy(sys, "Hello World!");

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_strcpy_test_2(void)
{
	int		ret;
	char	*src = "AAAAAA";
	char	*tst = malloc(13);
	char	*sys = malloc(13);

	tst = ft_strcpy(tst, "Hello World!");
	sys = strcpy(sys, "Hello World!");

	tst = ft_strcpy(tst, src);
	sys = strcpy(sys, src);

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_strcpy_test_3(void)
{
	int		ret;
	char	*tst = malloc(11);
	char	*sys = malloc(11);

	tst = ft_strcpy(tst, "Hello World!!!");
	sys = strcpy(sys, "Hello World!!!");

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_strcpy_test_4(void)
{
	int		ret;
	char	*tst = malloc(18);
	char	*sys = malloc(18);

	tst = ft_strcpy(tst, "Hello World!!!");
	sys = strcpy(sys, "Hello World!!!");

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_strcpy_test_5(void)
{
	int		ret;
	char	*sys = malloc(13);
	char	*tst = malloc(13);

	tst = ft_strcpy(tst, "");
	sys = strcpy(sys, "");

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_strcpy_test_6(void)
{
	char	*src = "Hello";

	ft_strcpy("", src);
	strcpy("", src);

	return (1);
}

int		ft_strcpy_test_7(void)
{
	int		ret;
	char	*sys = malloc(13);
	char	*tst = malloc(13);

	tst = ft_strcpy(tst, NULL);
	sys = strcpy(sys, NULL);

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_strcpy_test_8(void)
{
	ft_strcpy(NULL, "Hello World!");
	strcpy(NULL, "Hello World!");
	return (1);
}

int		ft_strcpy_test_9(void)
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
	}
	src[size - 1] = '\0';

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

void	load_tests_ft_strcpy(struct s_test_wrap *func)
{
	func->name = "FT_STRCPY";
	func->n_tests = 9;
	zero_tests(func->tests);
	load_test(&((func->tests)[0]), "Basic", ft_strcpy_test_1);
	load_test(&((func->tests)[1]), "Overwrite", ft_strcpy_test_2);
	load_test(&((func->tests)[2]), "Longer Src", ft_strcpy_test_3);
	load_test(&((func->tests)[3]), "Longer Dst", ft_strcpy_test_4);
	load_test(&((func->tests)[4]), "Empty Src", ft_strcpy_test_5);
	load_test(&((func->tests)[5]), "Empty Dst", ft_strcpy_test_6);
	load_test(&((func->tests)[6]), "NULL Src", ft_strcpy_test_7);
	load_test(&((func->tests)[7]), "NULL Dst", ft_strcpy_test_8);
	load_test(&((func->tests)[8]), "Long", ft_strcpy_test_9);
}
