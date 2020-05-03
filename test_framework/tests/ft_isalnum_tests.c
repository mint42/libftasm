#include "libasm.h"
#include "tester.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int		ft_isalnum_test_1(void)
{
	int		ret;
	char	tst[17];
	char	sys[17];

	tst[16] = '\0';
	sprintf(tst, "%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
	(_ft_isalnum('/') ? 1 : 0),
	(_ft_isalnum('0') ? 1 : 0),
	(_ft_isalnum('4') ? 1 : 0),
	(_ft_isalnum('9') ? 1 : 0),
	(_ft_isalnum(':') ? 1 : 0),
	(_ft_isalnum('@') ? 1 : 0),
	(_ft_isalnum('A') ? 1 : 0),
	(_ft_isalnum('K') ? 1 : 0),
	(_ft_isalnum('Z') ? 1 : 0),
	(_ft_isalnum('[') ? 1 : 0),
	(_ft_isalnum(96) ? 1 : 0),
	(_ft_isalnum('a') ? 1 : 0),
	(_ft_isalnum('K') ? 1 : 0),
	(_ft_isalnum('z') ? 1 : 0),
	(_ft_isalnum(123) ? 1 : 0),
	(_ft_isalnum(127) ? 1 : 0));

	sys[16] = '\0';
	sprintf(sys, "%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
	(isalnum('/') ? 1 : 0),
	(isalnum('0') ? 1 : 0),
	(isalnum('4') ? 1 : 0),
	(isalnum('9') ? 1 : 0),
	(isalnum(':') ? 1 : 0),
	(isalnum('@') ? 1 : 0),
	(isalnum('A') ? 1 : 0),
	(isalnum('K') ? 1 : 0),
	(isalnum('Z') ? 1 : 0),
	(isalnum('[') ? 1 : 0),
	(isalnum(96) ? 1 : 0),
	(isalnum('a') ? 1 : 0),
	(isalnum('K') ? 1 : 0),
	(isalnum('z') ? 1 : 0),
	(isalnum(123) ? 1 : 0),
	(isalnum(127) ? 1 : 0));

	ret = (strcmp(tst, sys)) ? 1 : 0;
	return (ret);
}

void	load_tests_ft_isalnum(struct s_test_wrap *func)
{
	func->name = "FT_ISALNUM";
	func->n_tests = 1;
	zero_tests(func->tests);
	load_test(&((func->tests)[0]), "Basic", ft_isalnum_test_1);
}
