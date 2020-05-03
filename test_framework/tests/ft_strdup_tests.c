#include "libasm.h"
#include "tester.h"
#include <stdlib.h>
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

void	load_tests_ft_strdup(struct s_test_wrap *func)
{
	func->name = "FT_STRDUP";
	func->n_tests = 1;
	zero_tests(func->tests);
	load_test(&((func->tests)[0]), "Basic", ft_strdup_test_1);
}
