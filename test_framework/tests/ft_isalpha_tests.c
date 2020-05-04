#include "libasm.h"
#include "tester.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int		ft_isalpha_test_1(void)
{
	int		ret;
	char	tst[12];
	char	sys[12];

	tst[11] = '\0';
	sprintf(tst, "%d%d%d%d%d%d%d%d%d%d%d",
	(ft_isalpha('@') ? 1 : 0),
	(ft_isalpha('A') ? 1 : 0),
	(ft_isalpha('K') ? 1 : 0),
	(ft_isalpha('Z') ? 1 : 0),
	(ft_isalpha('[') ? 1 : 0),
	(ft_isalpha(96)), 
	(ft_isalpha('a') ? 1 : 0),
	(ft_isalpha('K') ? 1 : 0),
	(ft_isalpha('z') ? 1 : 0),
	(ft_isalpha(123) ? 1 : 0),
	(ft_isalpha(127) ? 1 : 0));

	sys[11] = '\0';
	sprintf(sys, "%d%d%d%d%d%d%d%d%d%d%d",
	(isalpha('@') ? 1 : 0),
	(isalpha('A') ? 1 : 0),
	(isalpha('K') ? 1 : 0),
	(isalpha('Z') ? 1 : 0),
	(isalpha('[') ? 1 : 0),
	(isalpha(96) ? 1 : 0),
	(isalpha('a') ? 1 : 0),
	(isalpha('K') ? 1 : 0),
	(isalpha('z') ? 1 : 0),
	(isalpha(123) ? 1 : 0),
	(isalpha(127) ? 1 : 0));

	ret = (strcmp(tst, sys)) ? 1 : 0;
	return (ret);
}

void	load_tests_ft_isalpha(struct s_test_wrap *func)
{
	func->name = "FT_ISALPHA";
	func->n_tests = 1;
	zero_tests(func->tests);
	load_test(&((func->tests)[0]), "Basic", ft_isalpha_test_1);
}
