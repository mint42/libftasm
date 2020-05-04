#include "libasm.h"
#include "tester.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int		ft_isdigit_test_1(void)
{
	int		ret;
	char	tst[6];
	char	sys[6];

	tst[5] = '\0';
	sprintf(tst, "%d%d%d%d%d",
	(ft_isdigit('/') ? 1 : 0),
	(ft_isdigit('0') ? 1 : 0),
	(ft_isdigit('4') ? 1 : 0),
	(ft_isdigit('9') ? 1 : 0),
	(ft_isdigit(':') ? 1 : 0));

	sys[5] = '\0';
	sprintf(sys, "%d%d%d%d%d",
	(isdigit('/') ? 1 : 0),
	(isdigit('0') ? 1 : 0),
	(isdigit('4') ? 1 : 0),
	(isdigit('9') ? 1 : 0),
	(isdigit(':') ? 1 : 0));

	ret = (strcmp(tst, sys)) ? 1 : 0;
	return (ret);
}

void	load_tests_ft_isdigit(struct s_test_wrap *func)
{
	func->name = "FT_ISDIGIT";
	func->n_tests = 1;
	zero_tests(func->tests);
	load_test(&((func->tests)[0]), "Basic", ft_isdigit_test_1);
}
