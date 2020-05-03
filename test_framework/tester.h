#ifndef TESTER_H
# define TESTER_H

#include "tests.h"
#include <stddef.h>

struct s_test
{
	char	*test_name;
	int		(*test_func)(void);
};

struct s_test_wrap
{
	char			*name;
	struct s_test	tests[MAX_TESTS];
	size_t			n_tests;
};


void	zero_tests(struct s_test *tests);
void	load_test(struct s_test *test, char *name, int (*test_func)(void));

#endif
