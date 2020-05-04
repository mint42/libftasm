#include "libasm.h"
#include "tester.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int		ft_read_test_1(void)
{
	int		fd_tst_src;
	int		fd_tst_dst;
	int		fd_sys_src;
	int		fd_sys_dst;
	int		tst = 0;
	int		sys = 0;
	int		red_tst = 0;
	int		red_sys = 0;
	char	buf_tst[255];
	char	buf_sys[255];
	int		errno_tst = 0;
	int		errno_sys = 0;

	fd_tst_src = open("./Makefile", O_RDONLY);
	fd_tst_dst = open("./test_tst_read.txt", O_RDWR);
	fd_sys_src = open("./Makefile", O_RDONLY);
	fd_sys_dst = open("./test_sys_read.txt", O_RDWR);

	while(42)
	{
		red_tst = _ft_read(fd_tst_src, buf_tst, 255);
		if (red_tst == -1)
			errno_tst = errno;
		red_sys = read(fd_sys_src, buf_sys, 255);
		if (red_sys == -1)
			errno_sys = errno;

		if (errno_tst != errno_sys)
			return (1);
		if (errno_tst)
		{
			if (red_tst == red_sys)
				return (0);
			return (1);
		}
		if (red_tst != red_sys)
			return (1);
		if (red_tst == 0)
			return (0);
		tst = tst + red_tst;
		sys = sys + red_sys;
		write(fd_tst_dst, buf_tst, red_tst);
		write(fd_sys_dst, buf_sys, red_sys);
	}
	return (1);
}

int		ft_read_test_2(void)
{
	int		red_tst = 0;
	int		red_sys = 0;
	int		errno_tst = 0;
	int		errno_sys = 0;

	red_tst = _ft_read(-1, "Hello World", 13);
	if (red_tst == -1)
		errno_tst = errno;
	red_sys = read(-1, "Hello World", 13);
	if (red_sys == -1)
		errno_sys = errno;
	if (errno_tst == errno_sys && red_tst == red_sys)
		return (0);
	return (1);
}

int		ft_read_test_3(void)
{
	int		fd;
	int		red_tst = 0;
	int		red_sys = 0;
	int		errno_tst = 0;
	int		errno_sys = 0;

	fd = open("BAD", O_RDONLY);

	red_tst = _ft_read(fd, "Hello World", 13);
	if (red_tst == -1)
		errno_tst = errno;
	red_sys = read(fd, "Hello World", 13);
	if (red_sys == -1)
		errno_sys = errno;
	if (errno_tst == errno_sys && red_tst == red_sys)
		return (0);
	return (1);
}

int		ft_read_test_4(void)
{
	int		fd;
	int		red_tst = 0;
	int		red_sys = 0;
	int		errno_tst = 0;
	int		errno_sys = 0;

	fd = open("./Makefile", O_WRONLY);

	red_tst = _ft_read(fd, "Hello World", 13);
	if (red_tst == -1)
		errno_tst = errno;
	red_sys = read(fd, "Hello World", 13);
	if (red_sys == -1)
		errno_sys = errno;
	if (errno_tst == errno_sys && red_tst == red_sys)
		return (0);
	return (1);
}


int		ft_read_test_5(void)
{
	int		fd;
	int		red_tst = 0;
	int		red_sys = 0;
	int		errno_tst = 0;
	int		errno_sys = 0;

	fd = open("./Makefile", O_RDONLY);

	red_tst = _ft_read(fd, "", 2);
	if (red_tst == -1)
		errno_tst = errno;
	red_sys = read(fd, "", 2);
	if (red_sys == -1)
		errno_sys = errno;
	if (errno_tst == errno_sys && red_tst == red_sys)
		return (0);
	return (1);
}

int		ft_read_test_6(void)
{
	int		fd;
	int		red_tst = 0;
	int		red_sys = 0;
	int		errno_tst = 0;
	int		errno_sys = 0;

	fd = open("./Makefile", O_RDONLY);

	red_tst = _ft_read(fd, NULL, 2);
	if (red_tst == -1)
		errno_tst = errno;
	red_sys = read(fd, NULL, 2);
	if (red_sys == -1)
		errno_sys = errno;
	if (errno_tst == errno_sys && red_tst == red_sys)
		return (0);
	return (1);
}

void	load_tests_ft_read(struct s_test_wrap *func)
{
	func->name = "FT_READ";
	func->n_tests = 6;
	zero_tests(func->tests);
	load_test(&((func->tests)[0]), "Valid fd", ft_read_test_1);
	load_test(&((func->tests)[1]), "Invalid fd", ft_read_test_2);
	load_test(&((func->tests)[2]), "Nonexistent file", ft_read_test_3);
	load_test(&((func->tests)[3]), "No read perms", ft_read_test_4);
	load_test(&((func->tests)[4]), "Empty Buf", ft_read_test_5);
	load_test(&((func->tests)[5]), "NULL Buf", ft_read_test_6);
}
