#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libasm.h"

int main()
{
	srand(0);
	char	*hello_world = "Hello World!";
	char	*empty = "";
	int		size = 0;

	int		fd_tst;
	int		fd_sys;

	fd_tst = open("./test.txt", O_RDWR);
	fd_sys = open("./system.txt", O_RDWR);

/*-------------------------------------------------
	ft_bzero
-------------------------------------------------*/
// {{{
//	printf("------------------------------------\n");
//	printf("   FT_BZERO:\n");
//	printf("------------------------------------\n");
//
//	char	array[10] = "1234567890";
//	char	*to_malloc = malloc(10);
//
//	write(1, array, 10);
//	_ft_bzero(array, 10);
//	write(1, array, 10);
//
//	write(1, to_malloc, 10);
//	_ft_bzero(to_malloc, 10);
//	write(1, to_malloc, 10); printf("\n\n");
// }}}
/*-------------------------------------------------
	ft_isascii
-------------------------------------------------*/
// {{{
	printf("------------------------------------\n");
	printf("   FT_ISASCII:\n");
	printf("------------------------------------\n");

printf("Test 1\n");

	dprintf(fd_tst, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
	(_ft_isascii(10) ? 1 : 0),
	(_ft_isascii(100) ? 1 : 0),
	(_ft_isascii(-8) ? 1 : 0),
	(_ft_isascii(90) ? 1 : 0),
	(_ft_isascii(127) ? 1 : 0),
	(_ft_isascii(128) ? 1 : 0),
	(_ft_isascii(0) ? 1 : 0),
	(_ft_isascii(99) ? 1 : 0),
	(_ft_isascii('z') ? 1 : 0));
	dprintf(fd_tst, "\n\n");

	dprintf(fd_sys, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
	(isascii(10) ? 1 : 0),
	(isascii(100) ? 1 : 0),
	(isascii(-8) ? 1 : 0),
	(isascii(90) ? 1 : 0),
	(isascii(127) ? 1 : 0),
	(isascii(128) ? 1 : 0),
	(isascii(0) ? 1 : 0),
	(isascii(99) ? 1 : 0),
	(isascii('z') ? 1 : 0));
	dprintf(fd_sys, "\n\n");

printf("\n");
// }}}
/*-------------------------------------------------
	ft_isalnum
-------------------------------------------------*/
//{{{
	printf("------------------------------------\n");
	printf("   FT_ISALNUM:\n");
	printf("------------------------------------\n");

printf("Test 1\n");

	dprintf(fd_tst, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
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
	dprintf(fd_tst, "\n\n");

	dprintf(fd_sys, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
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
	dprintf(fd_sys, "\n\n");

printf("\n");
//}}}
/*-------------------------------------------------
	ft_isalpha
-------------------------------------------------*/
//{{{
	printf("------------------------------------\n\n");
	printf("FT_ISALPHA:\n\n");
	printf("------------------------------------\n\n");

printf("Test 1\n");

	dprintf(fd_tst, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
	(_ft_isalpha('@') ? 1 : 0),
	(_ft_isalpha('A') ? 1 : 0),
	(_ft_isalpha('K') ? 1 : 0),
	(_ft_isalpha('Z') ? 1 : 0),
	(_ft_isalpha('[') ? 1 : 0),
	(_ft_isalpha(96)), 
	(_ft_isalpha('a') ? 1 : 0),
	(_ft_isalpha('K') ? 1 : 0),
	(_ft_isalpha('z') ? 1 : 0),
	(_ft_isalpha(123) ? 1 : 0),
	(_ft_isalpha(127) ? 1 : 0));
	dprintf(fd_tst, "\n\n");

	dprintf(fd_sys, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
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
	dprintf(fd_sys, "\n\n");

printf("\n");
//}}}
/*-------------------------------------------------
	ft_isdigit
-------------------------------------------------*/
// {{{
	printf("------------------------------------\n\n");
	printf("FT_ISDIGIT:\n\n");
	printf("------------------------------------\n\n");

printf("Test 1\n");

	dprintf(fd_tst, "%d\n%d\n%d\n%d\n%d\n",
	(_ft_isdigit('/') ? 1 : 0),
	(_ft_isdigit('0') ? 1 : 0),
	(_ft_isdigit('4') ? 1 : 0),
	(_ft_isdigit('9') ? 1 : 0),
	(_ft_isdigit(':') ? 1 : 0));
	dprintf(fd_tst, "\n\n");

	dprintf(fd_sys, "%d\n%d\n%d\n%d\n%d\n",
	(isdigit('/') ? 1 : 0),
	(isdigit('0') ? 1 : 0),
	(isdigit('4') ? 1 : 0),
	(isdigit('9') ? 1 : 0),
	(isdigit(':') ? 1 : 0));
	dprintf(fd_sys, "\n\n");

printf("\n");
// }}}
/*-------------------------------------------------
	ft_strlen
-------------------------------------------------*/
/ {{{
	printf("------------------------------------\n");
	printf("   FT_STRLEN:\n");
	printf("------------------------------------\n");

	size_t	tst_len;
	size_t	sys_len;

printf("Test 1: Hello World\n");

	tst_len = _ft_strlen(hello_world);
	dprintf(fd_tst, "%ld", tst_len);
	dprintf(fd_tst, "\n\n");

	sys_len = strlen(hello_world);
	dprintf(fd_sys, "%ld", sys_len);
	dprintf(fd_sys, "\n\n");

printf("Test 2: Empty String\n");

	tst_len = _ft_strlen(empty);
	dprintf(fd_tst, "%ld", tst_len);
	dprintf(fd_tst, "\n\n");

	sys_len = strlen(empty);
	dprintf(fd_sys, "%ld", sys_len);
	dprintf(fd_sys, "\n\n");

printf("Test 3: NULL String\n");

//	tst_len = _ft_strlen(NULL);
//	printfd(fd_tst, "STR:	|%s|\n", str);
//	printfd(fd_tst, "%ld", tst_len);
//	printfd(fd_tst, "\n\n");
//
//	sys_len = strlen(NULL);
//	printfd(fd_sys, "STR:	|%s|\n", str);
//	printfd(fd_sys, "%ld", sys_len);
//	printfd(fd_sys, "\n\n");

printf("Test 4: Long\n");

	size = (rand() % 10000) + 10000;
	char	str[size];

	for (int i = 0; i < size; i++)
	{
		str[i] = (rand() % 94) + 32;
	}
	str[size - 1] = '\0';

	tst_len = _ft_strlen(str);
	dprintf(fd_tst, "%ld", tst_len);
	dprintf(fd_tst, "\n\n");

	sys_len = strlen(str);
	dprintf(fd_sys, "%ld", sys_len);
	dprintf(fd_sys, "\n\n");

printf("\n");
// }}}
/*-------------------------------------------------
	ft_strcpy
-------------------------------------------------*/
// {{{
	printf("------------------------------------\n");
	printf("   FT_STRCPY:\n");
	printf("------------------------------------\n");

printf("Test 1: Hello World\n");

	char	*tst_dst_cpy1 = malloc(13);
	char	*sys_dst_cpy1 = malloc(13);

	tst_dst_cpy1 = _ft_strcpy(tst_dst_cpy1, hello_world);
	dprintf(fd_tst, "%s", tst_dst_cpy1);
	dprintf(fd_tst, "\n\n");

	sys_dst_cpy1 = strcpy(sys_dst_cpy1, hello_world);
	dprintf(fd_sys, "%s", sys_dst_cpy1);
	dprintf(fd_sys, "\n\n");

printf("Test 2: Overwrite\n");

	char	*src_cpy1 = "AAAAAA";

	tst_dst_cpy1 = _ft_strcpy(tst_dst_cpy1, src_cpy1);
	dprintf(fd_tst, "%s", tst_dst_cpy1);
	dprintf(fd_tst, "\n\n");

	sys_dst_cpy1 = strcpy(sys_dst_cpy1, src_cpy1);
	dprintf(fd_sys, "%s", sys_dst_cpy1);
	dprintf(fd_sys, "\n\n");

printf("Test 3: Longer Src\n");

//	char	*src_cpy2 = "Hello World!";
//	char	*tst_dst_cpy2 = malloc(11);
//	char	*sys_dst_cpy2 = malloc(11);
//
//	tst_dst_cpy2 = _ft_strcpy(tst_dst_cpy2, src_cpy2);
//	sys_dst_cpy2 = strcpy(sys_dst_cpy2, src_cpy2);
//
//	printf("    SRC STR:	|%s|\n", src_cpy2);
//	printf("TST DST STR:	|%s|\n", tst_dst_cpy2);
//	printf("SYS DST STR:	|%s|\n", sys_dst_cpy2);

printf("Test 4: Longer Dst\n");

	char	*tst_dst_cpy3 = malloc(15);
	char	*sys_dst_cpy3 = malloc(15);

	tst_dst_cpy3 = _ft_strcpy(tst_dst_cpy3, hello_world);
	dprintf(fd_tst, "%s", tst_dst_cpy3);
	dprintf(fd_tst, "\n\n");

	sys_dst_cpy3 = strcpy(sys_dst_cpy3, hello_world);
	dprintf(fd_sys, "%s", sys_dst_cpy3);
	dprintf(fd_sys, "\n\n");

printf("Test 5: Empty Src\n");

	char	*sys_dst_cpy4 = malloc(13);
	char	*tst_dst_cpy4 = malloc(13);

	tst_dst_cpy4 = _ft_strcpy(tst_dst_cpy4, empty);
	dprintf(fd_tst, "%s", tst_dst_cpy4);
	dprintf(fd_tst, "\n\n");

	sys_dst_cpy4 = strcpy(sys_dst_cpy4, empty);
	dprintf(fd_sys, "%s", sys_dst_cpy4);
	dprintf(fd_sys, "\n\n");

printf("Test 6: Empty Dst\n");

//	char	*src_cpy4 = "Hello World!";
//
//	_ft_strcpy("", src_cpy4);
//	strcpy("", src_cpy4);
//
//	printf("    SRC STR:	|%s|\n", src_cpy4);
//	printf("TST DST STR:	|%s|\n", "");
//	printf("SYS DST STR:	|%s|\n", "");

printf("Test 7: NULL Src\n");

//	char	*sys_dst_cpy5 = malloc(15);
//	char	*tst_dst_cpy5 = malloc(15);
//
//	tst_dst_cpy5 = _ft_strcpy(tst_dst_cpy5, 0);
//	sys_dst_cpy5 = strcpy(sys_dst_cpy5, 0);
//
//	printf("    SRC STR:	|%s|\n", 0);
//	printf("TST DST STR:	|%s|\n", tst_dst_cpy5);
//	printf("SYS DST STR:	|%s|\n", sys_dst_cpy5);

printf("Test 8: NULL Dst\n");

//	char	*src_cpy5 = "Hello World!";
//
//	_ft_strcpy(0, src_cpy5);
//	strcpy(0, src_cpy5);
//
//	printf("    SRC STR:	|%s|\n", src_cpy5);
//	printf("TST DST STR:	|%s|\n", 0);
//	printf("SYS DST STR:	|%s|\n", 0);

printf("Test 9: Long\n");

	size = (rand() % 10000) + 10000;
	char	*src_cpy6 = malloc(size);
	char	*tst_dst_cpy6 = malloc(size);
	char	*sys_dst_cpy6 = malloc(size);

	for (int i = 0; i < size; i++)
	{
		src_cpy6[i] = (rand() % 94) + 32;
	}
	src_cpy6[size - 1] = '\0';

	tst_dst_cpy6 = _ft_strcpy(tst_dst_cpy6, src_cpy6);
	dprintf(fd_tst, "%s", tst_dst_cpy6);
	dprintf(fd_tst, "\n\n");

	sys_dst_cpy6 = strcpy(sys_dst_cpy6, src_cpy6);
	dprintf(fd_sys, "%s", sys_dst_cpy6);
	dprintf(fd_sys, "\n\n");

printf("\n");
// }}}
/*-------------------------------------------------
	ft_strncpy
-------------------------------------------------*/
// {{{
	printf("------------------------------------\n");
	printf("   FT_STRNCPY:\n");
	printf("------------------------------------\n");

printf("Test 2: Overwrite\n");

	char	*tst_dst_ncpy1 = malloc(13);
	char	*sys_dst_ncpy1 = malloc(13);

	tst_dst_ncpy1 = _ft_strcpy(tst_dst_ncpy1, hello_world);
	tst_dst_ncpy1 = _ft_strncpy(tst_dst_ncpy1, src_cpy1, 5);
	dprintf(fd_tst, "%s", tst_dst_ncpy1);
	dprintf(fd_tst, "\n\n");

	sys_dst_ncpy1 = strcpy(sys_dst_ncpy1, hello_world);
	sys_dst_ncpy1 = strncpy(sys_dst_ncpy1, src_cpy1, 5);
	dprintf(fd_sys, "%s", sys_dst_ncpy1);
	dprintf(fd_sys, "\n\n");

printf("Test 2: Long\n");

	size = (rand() % 10000) + 10000;
	char	*src_ncpy2 = malloc(size);
	char	*tst_dst_ncpy2 = malloc(size);
	char	*sys_dst_ncpy2 = malloc(size);

	for (int i = 0; i < size; i++)
	{
		src_ncpy2[i] = (rand() % 94) + 32;

		tst_dst_ncpy2[i] = (rand() % 94) + 32;
		sys_dst_ncpy2[i] = tst_dst_ncpy2[i];
	}
	src_ncpy2[size - 1] = '\0';
	tst_dst_ncpy2[size - 1] = '\0';
	sys_dst_ncpy2[size - 1] = '\0';

	size = size - (rand() % 10000);

	tst_dst_ncpy2 = _ft_strncpy(tst_dst_ncpy2, src_ncpy2, size);
	dprintf(fd_tst, "%s", tst_dst_ncpy2);
	dprintf(fd_tst, "\n\n");

	sys_dst_ncpy2 = strncpy(sys_dst_ncpy2, src_ncpy2, size);
	dprintf(fd_sys, "%s", sys_dst_ncpy2);
	dprintf(fd_sys, "\n\n");

printf("\n");
// }}}
/*-------------------------------------------------
	ft_strcmp
-------------------------------------------------*/
// {{{
	printf("------------------------------------\n");
	printf("FT_STRCMP:\n");
	printf("------------------------------------\n");

printf("Test 1: Hello World\n");

	char	*cmp1 = "Hello Morld!";

	dprintf(fd_tst, "%d", _ft_strcmp(cmp1, hello_world));
	dprintf(fd_tst, "\n\n");

	dprintf(fd_sys, "%d", strcmp(cmp1, hello_world));
	dprintf(fd_sys, "\n\n");

printf("Test 2: Longer Src\n");

	char	*long_cmp = "Hello World!!!";

	dprintf(fd_tst, "%d", _ft_strcmp(cmp1, long_cmp));
	dprintf(fd_tst, "\n\n");

	dprintf(fd_sys, "%d", strcmp(cmp1, long_cmp));
	dprintf(fd_sys, "\n\n");

printf("Test 3: Longer Dst\n");

	dprintf(fd_tst, "%d", _ft_strcmp(long_cmp, cmp1));
	dprintf(fd_tst, "\n\n");

	dprintf(fd_sys, "%d", strcmp(long_cmp, cmp1));
	dprintf(fd_sys, "\n\n");

printf("Test 4: Empty Src\n");

	dprintf(fd_tst, "%d", _ft_strcmp(hello_world, empty));
	dprintf(fd_tst, "\n\n");

	dprintf(fd_sys, "%d", strcmp(hello_world, empty));
	dprintf(fd_sys, "\n\n");

printf("Test 5: Empty Dst\n");

	dprintf(fd_tst, "%d", _ft_strcmp(empty, hello_world));
	dprintf(fd_tst, "\n\n");

	dprintf(fd_sys, "%d", strcmp(empty, hello_world));
	dprintf(fd_sys, "\n\n");

printf("Test 6: NULL Src\n");

//	printf("SRC STR:	|%s|\n", 0);
//	printf("DST STR:	|%s|\n", src_cmp1);
//
//	printf("tst cmp:	|%ld|\n", _ft_strcmp(src_cmp1, 0));
//	printf("sys cmp:	|%ld|\n", strcmp(src_cmp1, 0));

printf("Test 7: NULL Dst\n");

//	printf("SRC STR:	|%s|\n", src_cmp1);
//	printf("DST STR:	|%s|\n", 0);
//
//	printf("tst cmp:	|%ld|\n", _ft_strcmp(0, src_cmp1));
//	printf("sys cmp:	|%ld|\n", strcmp(0, src_cmp1));

printf("Test 8: Long\n");

	int		size2;

	size = (rand() % 10000) + 10000;
	size2 = size - (rand() % 10000);

	char	*src_cmp6 = malloc(size);
	char	*dst_cmp6 = malloc(size);

	for (int i = 0; i < size; i++)
	{
		src_cmp6[i] = (rand() % 94) + 32;
		if (i < size2)
			dst_cmp6[i] = src_cmp6[i];
		else
			dst_cmp6[i] = (rand() % 94) + 32;
	}
	src_cmp6[size - 1] = '\0';
	dst_cmp6[size - 1] = '\0';

	dprintf(fd_tst, "%d", _ft_strcmp(dst_cmp6, src_cmp6));
	dprintf(fd_tst, "\n\n");

	dprintf(fd_sys, "%d", strcmp(dst_cmp6, src_cmp6));
	dprintf(fd_sys, "\n\n");

printf("\n");
// }}}
/*-------------------------------------------------
	ft_strdup
-------------------------------------------------*/
/// {{{
	printf("------------------------------------\n");
	printf("   FT_STRDUP:\n");
	printf("------------------------------------\n");

printf("Test 1: Basic\n");

	char	*tst_dst_dup1;
	char	*sys_dst_dup1;

	tst_dst_dup1 = _ft_strdup(hello_world);
	dprintf(fd_tst, "%s", tst_dst_dup1);
	dprintf(fd_tst, "\n\n");

	sys_dst_dup1 = strdup(hello_world);
	dprintf(fd_sys, "%s", sys_dst_dup1);
	dprintf(fd_sys, "\n\n");

printf("Test 2: Empty Src\n");

//	char	*sys_dst_dup4;
//	char	*tst_dst_dup4;
//
//	tst_dst_dup1 = _ft_strdup(empty);
//	dprintf(fd_tst, "%s", tst_dst_dup4);
//	dprintf(fd_tst, "\n\n");
//
//	sys_dst_dup1 = strdup(empty);
//	dprintf(fd_sys, "%s", sys_dst_dup4);
//	dprintf(fd_sys, "\n\n");

printf("Test 3: NULL Src\n");

//	char	*sys_dst_dup5;
//	char	*tst_dst_dup5;
//
//	tst_dst_dup5 = _ft_strdup(0);
//	sys_dst_dup5 = strdup(0);
//
//	printf("    SRC STR:	|%s|\n", 0);
//	printf("TST DST STR:	|%s|\n", tst_dst_dup5);
//	printf("SYS DST STR:	|%s|\n", sys_dst_dup5);

printf("Test 4: Long\n");

	size = (rand() % 10000) + 10000;
	char	*src_dup6 = malloc(size);
	char	*tst_dst_dup6;
	char	*sys_dst_dup6;

	for (int i = 0; i < size; i++)
	{
		src_dup6[i] = (rand() % 94) + 32;
	}
	src_dup6[size - 1] = '\0';

	tst_dst_dup6 = _ft_strdup(src_dup6);
	dprintf(fd_tst, "%s", tst_dst_dup6);
	dprintf(fd_tst, "\n\n");

	sys_dst_dup6 = strdup(src_dup6);
	dprintf(fd_sys, "%s", sys_dst_dup6);
	dprintf(fd_sys, "\n\n");

printf("\n");
// }}}
/*
	int fd_tst;
	int fd_sys;
	fd_sys = open("write_sys.txt", O_RDWR);
	fd_tst = open("write_tst.txt", O_RDWR);
	size_t write_sys_out;
	size_t write_tst_out;

	printf("====_ft_write tests========\n");
	write_sys_out = write(1, "hello_world from sc_write\n", 26);
	printf("write_sys_out |%ld|\n", write_sys_out);

	write_tst_out = _ft_write(1, "hello_world from _ft_write\n", 26);
	printf("write_tst_out |%ld|\n", write_tst_out);

	write_sys_out = write(fd_sys, "hello_world file from sc_write\n", 31);
	printf("write_tst_out file|%ld|\n", write_sys_out);

	write_tst_out = _ft_write(fd_tst, "hello_world file from _ft_write\n", 31);
	printf("write_tst_out file|%ld|\n", write_tst_out);

	close(fd_sys);
	close(fd_tst);

	fd_sys = open("write_sysw.txt", O_RDWR);
	fd_tst = open("write_tstw.txt", O_RDWR);

	write_sys_out = write(fd_sys, "hello_world from syscall\n", 25);
	printf("write_sys_out no file |%ld|\n", write_sys_out);
	write_tst_out = _ft_write(fd_tst, "hello_world from syscall\n", 25);
	printf("write_sys_out no file |%ld|\n", write_tst_out);

	write_sys_out = write(-1, "hello_world from syscall\n", 25);
	printf("write_sys_out error|%ld|\n", write_sys_out);
	write_tst_out = _ft_write(-1, "hello_world from syscall\n", 25);
	printf("write_tst_out error|%ld|\n", write_tst_out);

	write_sys_out = write(1, "hello_world from syscall\n", 0);
	printf("write_sys_out nobytes|%ld|\n", write_sys_out);
	write_tst_out = _ft_write(1, "hello_world from syscall\n", 0);
	printf("write_tst_out nobytes|%ld|\n", write_tst_out);
	close(fd_sys);
	close(fd_tst);

	_ft_read---------------

	int tst_bytes;
	int sys_bytes;
	char buff[255];

	printf("====_ft_read tests========\n");
	printf("read from normal STDIN with sc_read:\n ");
	while((sys_bytes = read(0, buff, 255)) > 0)
	{
		if (buff[sys_bytes - 1] == '\n')
		{
			break;
		}
	}
	buff[sys_bytes - 1] = '\0';

	printf("sys_bytes a_fter sc_read |%d|\n", sys_bytes);
	printf("STDIN from read is |%s|\n", buff);

	printf("read from normal STDIN with _ft_read:\n ");
	while((tst_bytes = _ft_read(0, buff, 255)) > 0)
	{
		if (buff[tst_bytes - 1] == '\n')
		{
			break;
		}
	}
	buff[tst_bytes - 1] = '\0';
	printf("tst_bytes a_fter _ft_read |%d|\n", tst_bytes);
	printf("STDIN from _ft_read is |%s|\n", buff);

	fd_sys = open("read_sys.txt",O_RDONLY);
	fd_tst = open("read_tst.txt",O_RDONLY);

	sys_bytes = _ft_read(fd_sys, buff, 255);
	buff[sys_bytes - 1] = '\0';
	printf("reading files:\n");
	printf("sys_bytes|%d|\n", sys_bytes);
	printf("sc_read |%s|\n", buff);

	tst_bytes = _ft_read(fd_tst, buff, 255);
	buff[tst_bytes - 1] = '\0';
	printf("tst_bytes|%d|\n", tst_bytes);
	printf("_ft_read |%s|\n", buff);

	close(fd_sys);
	close(fd_tst);

	fd_sys = open("read_sysw.txt", O_RDWR);
	fd_tst = open("read_tstw.txt", O_RDWR);

	sys_bytes = _ft_read(fd_sys, buff, 255);
	buff[sys_bytes - 1] = '\0';
	printf("reading ERROR files:\n");
	printf("sys_bytes|%d|\n", sys_bytes);
	printf("sc_read |%s|\n", buff);

	tst_bytes = _ft_read(fd_tst, buff, 255);
	buff[tst_bytes - 1] = '\0';
	printf("tst_bytes|%d|\n", tst_bytes);
	printf("_ft_read |%s|\n", buff);


	close(fd_sys);
	close(fd_tst);

	_ft_strdup---------------

	char *strdup_tst;
	char *strdup_sys;
	char  empty_string[50] = "";
	char  normal_string[50] = "hello wolrd!";
	char  long_string[60] = "HELLO WORLD, TODAY IM THE LONGEST STRING EVAHHHH!!!!!!";

	printf("====_ft_strdup tests========\n");
	strdup_sys = strdup(empty_string);
	printf("strdup empty sys |%s|\n", strdup_sys);
	strdup_tst = _ft_strdup(empty_string);
	printf("strdup empty tst |%s|\n", strdup_tst);
	free(strdup_sys);
	free(strdup_tst);

	strdup_sys = strdup(normal_string);
	printf("strdup normal sys |%s|\n", strdup_sys);
	strdup_tst = _ft_strdup(normal_string);
	printf("strdup normal tst |%s|\n", strdup_tst);
	free(strdup_sys);
	free(strdup_tst);

	strdup_sys = strdup(long_string);
	printf("strdup long sys |%s|\n", long_string);
	strdup_tst = _ft_strdup(normal_string);
	printf("strdup long tst |%s|\n", long_string);
	free(strdup_sys);
	free(strdup_tst);
*/
	return (0);
}

// vim: foldmarker={{{,}}} foldmethod=marker
