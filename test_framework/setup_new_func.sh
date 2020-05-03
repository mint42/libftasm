#!/bin/sh

if [ -z $1 ]
then
	exit 1;
fi

cd tests
touch "$1"_tests.c

TOUPPER=$(echo "$1" | tr '[:lower:]' '[:upper:]')

cat << EOF > "$1"_tests.c
#include "libasm.h"
#include "tester.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int		$1_test_1(void)
{
	int		ret;
	char	*tst;
	char	*sys;

	tst = sprintf("", _$1());
	sys = sprintf("", _$1());

	ret = (strcmp(tst, sys)) ? 1 : 0;
	if (tst)
		free(tst);
	if (sys)
		free(sys);
	return (ret);
}

void	load_tests_$1(struct s_test_wrap *func)
{
	func->name = "$TOUPPER";
	func->n_tests = 1;
	zero_tests(func->tests);
	load_test(&((func->tests)[0]), "Basic", $1_test_1);
}
EOF
