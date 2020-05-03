#include "libasm.h"
#include "tester.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strcmp_test_1(void)
{
	int		tst;
	int		sys;

	tst = _ft_strcmp("Hello Morld!", "Hello World!");
	sys = strcmp("Hello Morld!", "Hello World!");

	return ((tst == sys) ? 1 : 0);
}

int		ft_strcmp_test_2(void)
{
	int		tst;
	int		sys;

	tst = _ft_strcmp("Hello Morld!", "Hello World!!!");
	sys = strcmp("Hello Morld!", "Hello World!!!");

	return ((tst == sys) ? 1 : 0);
}

int		ft_strcmp_test_3(void)
{
	int		tst;
	int		sys;

	tst = _ft_strcmp("Hello World!!!", "Hello Morld!");
	sys = strcmp("Hello World!!!", "Hello Morld!");

	return ((tst == sys) ? 1 : 0);
}

int		ft_strcmp_test_4(void)
{
	int		tst;
	int		sys;

	tst = _ft_strcmp("Hello World!", "");
	sys = strcmp("Hello World!", "");

	return ((tst == sys) ? 1 : 0);
}

int		ft_strcmp_test_5(void)
{
	int		tst;
	int		sys;

	tst = _ft_strcmp("", "Hello World!");
	sys = strcmp("", "Hello World!");

	return ((tst == sys) ? 1 : 0);
}

int		ft_strcmp_test_6(void)
{
	int		tst;
	int		sys;

	tst = _ft_strcmp("Hello World!", NULL);
	sys = strcmp("Hello World!", NULL);

	return ((tst == sys) ? 1 : 0);
}

int		ft_strcmp_test_7(void)
{
	int		tst;
	int		sys;

	tst = _ft_strcmp(NULL, "Hello World!");
	sys = strcmp(NULL, "Hello World!");

	return ((tst == sys) ? 1 : 0);
}

int		ft_strcmp_test_8(void)
{
	int		size;
	int		size2;
	int		tst;
	int		sys;

	size = (rand() % 10000) + 10000;
	size2 = size - (rand() % 10000);

	char	*src = malloc(size);
	char	*dst = malloc(size);

	for (int i = 0; i < size; i++)
	{
		src[i] = (rand() % 94) + 32;
		if (i < size2)
			dst[i] = src[i];
		else
			dst[i] = (rand() % 94) + 32;
	}
	src[size - 1] = '\0';
	dst[size - 1] = '\0';

	tst = _ft_strcmp(dst, src);
	sys = strcmp(dst, src);

	return ((tst == sys) ? 1 : 0);
}

void	load_tests_ft_strcmp(struct s_test_wrap *func)
{
	func->name = "FT_STRCMP";
	func->n_tests = 8;
	zero_tests(func->tests);
	load_test(&((func->tests)[0]), "Basic", ft_strcmp_test_1);
	load_test(&((func->tests)[1]), "Longer Src", ft_strcmp_test_2);
	load_test(&((func->tests)[2]), "Longer Dst", ft_strcmp_test_3);
	load_test(&((func->tests)[3]), "Empty Src", ft_strcmp_test_4);
	load_test(&((func->tests)[4]), "Empty Dst", ft_strcmp_test_5);
	load_test(&((func->tests)[5]), "NULL Src", ft_strcmp_test_6);
	load_test(&((func->tests)[6]), "NULL Dst", ft_strcmp_test_7);
	load_test(&((func->tests)[7]), "Long", ft_strcmp_test_8);
}
