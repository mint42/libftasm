#include "libasm.h"
#include "tester.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

/*
**		STDIN
**
** int		ft_write_test(void)
** {
** 	int		tst;
** 	int		sys;
** 	int		bytes;
** 	char	buf[255];
** 
** 	printf("write from STDIN:\n ");
** 	while((bytes = _ft_write(STDIN_FD, buf, 255)) > 0)
** 	{
** 		tst = tst + bytes;
** 		printf("buf: %s\n", buf);
** 	}
** 	if (bytes == -1)
** 		return (1);
** 	printf("%d bytes write\n", tst);
** 	return (0);
** }
*/

int		ft_write_test_1(void)
{
	char	buf[255];
	int		red;
	int		fd_src;
	int		fd_tst_dst;
	int		fd_sys_dst;
	int		tst = 0;
	int		sys = 0;
	int		bytes_tst = 0;
	int		bytes_sys = 0;
	int		errno_tst = 0;
	int		errno_sys = 0;

	fd_src = open("./Makefile", O_RDONLY);
	fd_tst_dst = open("./test_tst_write.txt", O_WRONLY);
	fd_sys_dst = open("./test_sys_write.txt", O_WRONLY);

	while(42)
	{
		red = read(fd_src, buf, 255);
		bytes_tst = _ft_write(fd_tst_dst, buf, red);
		if (bytes_tst == -1)
			errno_tst = errno;
		bytes_sys = write(fd_sys_dst, buf, red);
		if (bytes_sys == -1)
			errno_sys = errno;
		if (errno_tst != errno_sys)
			return (1);
		if (errno_tst)
		{
			if (bytes_tst == bytes_sys)
				return (0);
			return (1);
		}
		if (bytes_tst != bytes_sys)
			return (1);
		if (bytes_tst == 0)
			return (0);
		tst = tst + bytes_tst;
		sys = sys + bytes_sys;
		write(fd_tst_dst, buf, bytes_tst);
		write(fd_sys_dst, buf, bytes_sys);
	}
	return (1);
}

int		ft_write_test_2(void)
{
	int		bytes_tst = 0;
	int		bytes_sys = 0;
	int		errno_tst = 0;
	int		errno_sys = 0;

	bytes_tst = _ft_write(-1, "Hello World!", 13);
	if (bytes_tst == -1)
		errno_tst = errno;
	bytes_sys = write(-1, "Hello World!", 13);
	if (bytes_sys == -1)
		errno_sys = errno;
	if (errno_tst == errno_sys && bytes_tst == bytes_sys)
		return (0);
	return (1);
}

int		ft_write_test_3(void)
{
	int		fd;
	int		bytes_tst = 0;
	int		bytes_sys = 0;
	int		errno_tst = 0;
	int		errno_sys = 0;

	fd = open("BAD", O_WRONLY);

	bytes_tst = _ft_write(fd, "Hello World!", 13);
	if (bytes_tst == -1)
		errno_tst = errno;
	bytes_sys = write(fd, "Hello World!", 13);
	if (bytes_sys == -1)
		errno_sys = errno;
	if (errno_tst == errno_sys && bytes_tst == bytes_sys)
		return (0);
	return (1);
}

int		ft_write_test_4(void)
{
	int		fd;
	int		bytes_tst = 0;
	int		bytes_sys = 0;
	int		errno_tst = 0;
	int		errno_sys = 0;

	fd = open("./Makefile", O_RDONLY);

	bytes_tst = _ft_write(fd, "Hello World!", 13);
	if (bytes_tst == -1)
		errno_tst = errno;
	bytes_sys = write(fd, "Hello World!", 13);
	if (bytes_sys == -1)
		errno_sys = errno;
	if (errno_tst == errno_sys && bytes_tst == bytes_sys)
		return (0);
	return (1);
}

int		ft_write_test_5(void)
{
	int		fd_tst;
	int		fd_sys;
	int		bytes_tst = 0;
	int		bytes_sys = 0;
	int		errno_tst = 0;
	int		errno_sys = 0;

	fd_tst = open("./test_tst_write.txt", O_WRONLY);
	fd_sys = open("./test_sys_write.txt", O_WRONLY);

	bytes_tst = _ft_write(fd_tst, "", 2);
	if (bytes_tst == -1)
		errno_tst = errno;
	bytes_sys = write(fd_sys, "", 2);
	if (bytes_sys == -1)
		errno_sys = errno;
	if (errno_tst == errno_sys && bytes_tst == bytes_sys)
		return (0);
	return (1);
}

int		ft_write_test_6(void)
{
	int		fd_tst;
	int		fd_sys;
	int		bytes_tst = 0;
	int		bytes_sys = 0;
	int		errno_tst = 0;
	int		errno_sys = 0;

	fd_tst = open("./test_tst_write.txt", O_WRONLY);
	fd_sys = open("./test_sys_write.txt", O_WRONLY);

	bytes_tst = _ft_write(fd_tst, NULL, 2);
	if (bytes_tst == -1)
		errno_tst = errno;
	bytes_sys = write(fd_sys, NULL, 2);
	if (bytes_sys == -1)
		errno_sys = errno;
	if (errno_tst == errno_sys && bytes_tst == bytes_sys)
		return (0);
	return (1);
}

void	load_tests_ft_write(struct s_test_wrap *func)
{
	func->name = "FT_WRITE";
	func->n_tests = 6;
	zero_tests(func->tests);
	load_test(&((func->tests)[0]), "Valid fd", ft_write_test_1);
	load_test(&((func->tests)[1]), "Invalid fd", ft_write_test_2);
	load_test(&((func->tests)[2]), "Nonexistent file", ft_write_test_3);
	load_test(&((func->tests)[3]), "No write perms", ft_write_test_4);
	load_test(&((func->tests)[4]), "Empty Buf", ft_write_test_5);
	load_test(&((func->tests)[5]), "NULL Buf", ft_write_test_6);
}
