#include "libasm.h"
#include "tester.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strncpy_test_1(void)
{
	int		ret;
	char	*tst = malloc(13);
	char	*sys = malloc(13);

	tst = ft_strncpy(tst, "Hello World!", 13);
	sys = strncpy(sys, "Hello World!", 13);

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_strncpy_test_2(void)
{
	int		ret;
	char	*src = "AAAAAA";
	char	*tst = malloc(13);
	char	*sys = malloc(13);

	tst = ft_strncpy(tst, "Hello World!", 13);
	sys = strncpy(sys, "Hello World!", 13);

	tst = ft_strncpy(tst, src, 3);
	sys = strncpy(sys, src, 3);

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_strncpy_test_3(void)
{
	int		ret;
	char	*tst = malloc(11);
	char	*sys = malloc(11);

	tst = ft_strncpy(tst, "Hello World!!!", 16);
	sys = strncpy(sys, "Hello World!!!", 16);

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_strncpy_test_4(void)
{
	int		ret;
	char	*tst = malloc(18);
	char	*sys = malloc(18);

	tst = ft_strncpy(tst, "Hello World!!!", 16);
	sys = strncpy(sys, "Hello World!!!", 16);

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_strncpy_test_5(void)
{
	int		ret;
	char	*sys = malloc(13);
	char	*tst = malloc(13);

	tst = ft_strncpy(tst, "", 1);
	sys = strncpy(sys, "", 1);

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_strncpy_test_6(void)
{
	char	*src = "Hello";

	ft_strncpy("", src, 6);
	strncpy("", src, 6);

	return (1);
}

int		ft_strncpy_test_7(void)
{
	int		ret;
	char	*sys = malloc(13);
	char	*tst = malloc(13);

	tst = ft_strncpy(tst, NULL, 1);
	sys = strncpy(sys, NULL, 1);

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

int		ft_strncpy_test_8(void)
{
	ft_strncpy(NULL, "Hello World!", 1);
	strncpy(NULL, "Hello World!", 1);

	return (1);
}

int		ft_strncpy_test_9(void)
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

		tst[i] = (rand() % 94) + 32;
		sys[i] = tst[i];
	}
	src[size - 1] = '\0';
	tst[size - 1] = '\0';
	sys[size - 1] = '\0';

	size = size - (rand() % 10000);
	tst = ft_strncpy(tst, src, size);
	sys = strncpy(sys, src, size);

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if  (src)
		free(src);
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

void	load_tests_ft_strncpy(struct s_test_wrap *func)
{
	func->name = "FT_STRNCPY";
	func->n_tests = 9;
	zero_tests(func->tests);
	load_test(&((func->tests)[0]), "Basic", ft_strncpy_test_1);
	load_test(&((func->tests)[1]), "Overwrite", ft_strncpy_test_2);
	load_test(&((func->tests)[2]), "Longer Src", ft_strncpy_test_3);
	load_test(&((func->tests)[3]), "Longer Dst", ft_strncpy_test_4);
	load_test(&((func->tests)[4]), "Empty Src", ft_strncpy_test_5);
	load_test(&((func->tests)[5]), "Empty Dst", ft_strncpy_test_6);
	load_test(&((func->tests)[6]), "NULL Src", ft_strncpy_test_7);
	load_test(&((func->tests)[7]), "NULL Dst", ft_strncpy_test_8);
	load_test(&((func->tests)[8]), "Long", ft_strncpy_test_9);
}
