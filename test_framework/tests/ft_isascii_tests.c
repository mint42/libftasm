#include "libasm.h"
#include "tester.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int		ft_isascii_test_1(void)
{
	int		ret;
	char	tst[10];
	char	sys[10];

	tst[9] = '\0';
	sprintf(tst, "%d%d%d%d%d%d%d%d%d",
	(ft_isascii(10) ? 1 : 0),
	(ft_isascii(100) ? 1 : 0),
	(ft_isascii(-8) ? 1 : 0),
	(ft_isascii(90) ? 1 : 0),
	(ft_isascii(127) ? 1 : 0),
	(ft_isascii(128) ? 1 : 0),
	(ft_isascii(0) ? 1 : 0),
	(ft_isascii(99) ? 1 : 0),
	(ft_isascii('z') ? 1 : 0));

	sys[9] = '\0';
	sprintf(sys, "%d%d%d%d%d%d%d%d%d",
	(isascii(10) ? 1 : 0),
	(isascii(100) ? 1 : 0),
	(isascii(-8) ? 1 : 0),
	(isascii(90) ? 1 : 0),
	(isascii(127) ? 1 : 0),
	(isascii(128) ? 1 : 0),
	(isascii(0) ? 1 : 0),
	(isascii(99) ? 1 : 0),
	(isascii('z') ? 1 : 0));

	ret = (strcmp(tst, sys)) ? 1 : 0;
	return (ret);
}

void	load_tests_ft_isascii(struct s_test_wrap *func)
{
	func->name = "FT_ISASCII";
	func->n_tests = 1;
	zero_tests(func->tests);
	load_test(&((func->tests)[0]), "Basic", ft_isascii_test_1);
}
