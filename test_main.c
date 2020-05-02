#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "libasm.h"

int main()
{

/*-------------------------------------------------
	ft_strlen
-------------------------------------------------*/

	printf("------------------------------------\n");
	printf("   FT_STRLEN:\n");
	printf("------------------------------------\n");

	size_t	tst_len;
	size_t	sys_len;

printf("------------------------\n");
printf("Test 1: Basic\n");
printf("------------------------\n");

	char	*str = "Hello World!";

	tst_len = _ft_strlen(str);
	sys_len = strlen(str);
	printf("STR:		|%s|\n", str);
	printf("len tst:	|%ld|\n", tst_len);
	printf("len sys:	|%ld|\n", sys_len);

printf("------------------------\n");
printf("Test 2: Empty String\n");
printf("------------------------\n");

	tst_len = _ft_strlen("");
	sys_len = strlen("");
	printf("STR:		|%s|\n", "");
	printf("len tst:	|%ld|\n", tst_len);
	printf("len sys:	|%ld|\n", sys_len);

printf("\n");
printf("Test 3: NULL String\n");
printf("\n");

//	tst_len = _ft_strlen(NULL);
//	sys_len = strlen(NULL);
//	printf("STR:		|%s|\n", "NULL");
//	printf("len tst:	|%s|\n", tst_len);
//	printf("len sys:	|%s|\n", sys_len);

printf("------------------------\n");
printf("Test 4: Long String\n");
printf("------------------------\n");

	char	str2[5000];

	for(int i = 0; i < 5000; i++)
	{
		str2[i] = (rand() % 94) + 32;
	}
	str2[4999] = '\0';

	tst_len = _ft_strlen(str2);
	sys_len = strlen(str2);
	printf("STR:		|%s|\n", str2);
	printf("len tst:	|%ld|\n", tst_len);
	printf("len sys:	|%ld|\n", sys_len);

	printf("\n");

/*-------------------------------------------------
	ft_strcpy
-------------------------------------------------*/

	printf("------------------------------------\n");
	printf("   FT_STRCPY:\n");
	printf("------------------------------------\n");

printf("------------------------\n");
printf("Test 1: Basic\n");
printf("------------------------\n");

	char	*src_cpy1 = "Hello World!";
	char	*tst_dst_cpy1 = malloc(13);
	char	*sys_dst_cpy1 = malloc(13);

	tst_dst_cpy1 = _ft_strcpy(tst_dst_cpy1, src_cpy1);
	sys_dst_cpy1 = strcpy(sys_dst_cpy1, src_cpy1);

	printf("    SRC STR:	|%s|\n", src_cpy1);
	printf("TST DST STR:	|%s|\n", tst_dst_cpy1);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy1);

printf("------------------------\n");
printf("Test 2: Different\n");
printf("------------------------\n");

	char	*src_cpy1_5 = "AAAAAA";

	tst_dst_cpy1 = _ft_strcpy(tst_dst_cpy1, src_cpy1_5);
	sys_dst_cpy1 = strcpy(sys_dst_cpy1, src_cpy1_5);

	printf("    SRC STR:	|%s|\n", src_cpy1_5);
	printf("TST DST STR:	|%s|\n", tst_dst_cpy1);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy1);


printf("------------------------\n");
printf("Test 3: Longer Src\n");
printf("------------------------\n");

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

printf("------------------------\n");
printf("Test 4: Longer Dst\n");
printf("------------------------\n");

	char	*src_cpy3 = "Hello World!";
	char	*tst_dst_cpy3 = malloc(15);
	char	*sys_dst_cpy3 = malloc(15);

	tst_dst_cpy3 = _ft_strcpy(tst_dst_cpy3, src_cpy3);
	sys_dst_cpy3 = strcpy(sys_dst_cpy3, src_cpy3);

	printf("    SRC STR:	|%s|\n", src_cpy3);
	printf("TST DST STR:	|%s|\n", tst_dst_cpy3);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy3);

printf("------------------------\n");
printf("Test 5: Empty Src\n");
printf("------------------------\n");

	char	*sys_dst_cpy4 = malloc(13);
	char	*tst_dst_cpy4 = malloc(13);

	tst_dst_cpy4 = _ft_strcpy(tst_dst_cpy4, "");
	sys_dst_cpy4 = strcpy(sys_dst_cpy4, "");

	printf("    SRC STR:	|%s|\n", "");
	printf("TST DST STR:	|%s|\n", tst_dst_cpy4);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy4);

printf("------------------------\n");
printf("Test 6: Empty Dst\n");
printf("------------------------\n");

//	char	*src_cpy4 = "Hello World!";
//
//	_ft_strcpy("", src_cpy4);
//	strcpy("", src_cpy4);
//
//	printf("    SRC STR:	|%s|\n", src_cpy4);
//	printf("TST DST STR:	|%s|\n", "");
//	printf("SYS DST STR:	|%s|\n", "");

printf("------------------------\n");
printf("Test 7: NULL Src\n");
printf("------------------------\n");

//	char	*sys_dst_cpy5 = malloc(15);
//	char	*tst_dst_cpy5 = malloc(15);
//
//	tst_dst_cpy5 = _ft_strcpy(tst_dst_cpy5, 0);
//	sys_dst_cpy5 = strcpy(sys_dst_cpy5, 0);
//
//	printf("    SRC STR:	|%s|\n", 0);
//	printf("TST DST STR:	|%s|\n", tst_dst_cpy5);
//	printf("SYS DST STR:	|%s|\n", sys_dst_cpy5);

printf("------------------------\n");
printf("Test 8: NULL Dst\n");
printf("------------------------\n");

//	char	*src_cpy5 = "Hello World!";
//
//	_ft_strcpy(0, src_cpy5);
//	strcpy(0, src_cpy5);
//
//	printf("    SRC STR:	|%s|\n", src_cpy5);
//	printf("TST DST STR:	|%s|\n", 0);
//	printf("SYS DST STR:	|%s|\n", 0);

printf("------------------------\n");
printf("Test 9: Long\n");
printf("------------------------\n");

	char	*src_cpy6 = malloc(5000);
	char	*tst_dst_cpy6 = malloc(5000);
	char	*sys_dst_cpy6 = malloc(5000);

	for(int i = 0; i < 5000; i++)
	{
		src_cpy6[i] = (rand() % 94) + 32;
	}
	src_cpy6[4999] = '\0';

	tst_dst_cpy6 = _ft_strcpy(tst_dst_cpy6, src_cpy6);
	sys_dst_cpy6 = strcpy(sys_dst_cpy6, src_cpy6);

	printf("    SRC STR:	|%s|\n", src_cpy6);
	printf("TST DST STR:	|%s|\n", tst_dst_cpy6);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy6);

printf("\n");

/*-------------------------------------------------
	ft_strncpy
-------------------------------------------------*/

	printf("------------------------------------\n");
	printf("   FT_STRNCPY:\n");
	printf("------------------------------------\n");

printf("------------------------\n");
printf("Test 2: Basic\n");
printf("------------------------\n");

	char	*src_ncpy1_5 = "AAAAAA";
	char	*tst_dst_ncpy1 = malloc(13);
	char	*sys_dst_ncpy1 = malloc(13);

	tst_dst_ncpy1 = _ft_strcpy(tst_dst_ncpy1, "Hello World!");
	sys_dst_ncpy1 = strcpy(sys_dst_ncpy1, "Hello World!");

	tst_dst_ncpy1 = _ft_strncpy(tst_dst_ncpy1, src_ncpy1_5, 5);
	sys_dst_ncpy1 = strncpy(sys_dst_ncpy1, src_ncpy1_5, 5);

	printf("    SRC STR:	|%s|\n", src_ncpy1_5);
	printf("TST DST STR:	|%s|\n", tst_dst_ncpy1);
	printf("SYS DST STR:	|%s|\n", sys_dst_ncpy1);


printf("------------------------\n");
printf("Test 2: Long\n");
printf("------------------------\n");

	char	*src_ncpy2 = "Hello World!";
	char	*tst_dst_ncpy2 = malloc(15);
	char	*sys_dst_ncpy2 = malloc(15);

	tst_dst_ncpy2 = _ft_strncpy(tst_dst_ncpy2, src_ncpy2, 15);
	sys_dst_ncpy2 = strncpy(sys_dst_ncpy2, src_ncpy2, 15);

	printf("    SRC STR:	|%s|\n", src_ncpy2);
	printf("TST DST STR:	|%s|\n", tst_dst_ncpy2);
	printf("SYS DST STR:	|%s|\n", sys_dst_ncpy2);

printf("\n");


/*-------------------------------------------------
	ft_strcmp
-------------------------------------------------*/

	printf("------------------------------------\n");
	printf("FT_STRCMP:\n");
	printf("------------------------------------\n");

printf("------------------------\n");
printf("Test 1: Basic\n");
printf("------------------------\n");

	char	*src_cmp1 = "Hello World!";
	char	*dst_cmp1 = "Hello Morld!";

	printf("SRC STR:	|%s|\n", src_cmp1);
	printf("DST STR:	|%s|\n", dst_cmp1);

	printf("tst cmp:	|%d|\n", _ft_strcmp(dst_cmp1, src_cmp1));
	printf("sys cmp:	|%d|\n", strcmp(dst_cmp1, src_cmp1));

printf("------------------------\n");
printf("Test 2: Longer Src\n");
printf("------------------------\n");

	char	*long_cmp = "Hello World!!!";

	printf("SRC STR:	|%s|\n", long_cmp);
	printf("DST STR:	|%s|\n", dst_cmp1);

	printf("tst cmp:	|%d|\n", _ft_strcmp(dst_cmp1, long_cmp));
	printf("sys cmp:	|%d|\n", strcmp(dst_cmp1, long_cmp));

printf("------------------------\n");
printf("Test 3: Longer Dst\n");
printf("------------------------\n");

	printf("SRC STR:	|%s|\n", dst_cmp1);
	printf("DST STR:	|%s|\n", long_cmp);

	printf("tst cmp:	|%d|\n", _ft_strcmp(long_cmp, dst_cmp1));
	printf("sys cmp:	|%d|\n", strcmp(long_cmp, dst_cmp1));

printf("------------------------\n");
printf("Test 4: Empty Src\n");
printf("------------------------\n");

	printf("SRC STR:	|%s|\n", "");
	printf("DST STR:	|%s|\n", src_cmp1);

	printf("tst cmp:	|%d|\n", _ft_strcmp(src_cmp1, ""));
	printf("sys cmp:	|%d|\n", strcmp(src_cmp1, ""));

printf("------------------------\n");
printf("Test 5: Empty Dst\n");
printf("------------------------\n");

	printf("SRC STR:	|%s|\n", src_cmp1);
	printf("DST STR:	|%s|\n", "");

	printf("tst cmp:	|%d|\n", _ft_strcmp("", src_cmp1));
	printf("sys cmp:	|%d|\n", strcmp("", src_cmp1));

printf("------------------------\n");
printf("Test 6: NULL Src\n");
printf("------------------------\n");

//	printf("SRC STR:	|%s|\n", 0);
//	printf("DST STR:	|%s|\n", src_cmp1);
//
//	printf("tst cmp:	|%ld|\n", _ft_strcmp(src_cmp1, 0));
//	printf("sys cmp:	|%ld|\n", strcmp(src_cmp1, 0));

printf("------------------------\n");
printf("Test 7: NULL Dst\n");
printf("------------------------\n");

//	printf("SRC STR:	|%s|\n", src_cmp1);
//	printf("DST STR:	|%s|\n", 0);
//
//	printf("tst cmp:	|%ld|\n", _ft_strcmp(0, src_cmp1));
//	printf("sys cmp:	|%ld|\n", strcmp(0, src_cmp1));

printf("------------------------\n");
printf("Test 8: Long\n");
printf("------------------------\n");

//	char	*src_cmp6 = malloc(5000);
//	char	*dst_cmp6 = malloc(5000);
//
//	for(int i = 0; i < 5000; i++)
//	{
//		src_cmp6[i] = (rand() % 94) + 32;
//		if (i < 5000)
//			dst_cmp6[i] = src_cmp6[i];
//		else
//			dst_cmp6[i] = '*';
//	}
//	src_cmp6[4999] = '\0';
//	dst_cmp6[4999] = '\0';
//
//	printf("SRC STR:	|%s|\n", src_cmp6);
//	printf("DST STR:	|%s|\n", dst_cmp6);
//
//	printf("tst cmp:	|%ld|\n", _ft_strcmp(dst_cmp6, src_cmp6));
//	printf("sys cmp:	|%ld|\n", strcmp(dst_cmp6, src_cmp6));

printf("\n");

/*-------------------------------------------------
	ft_strdup
-------------------------------------------------*/

	printf("------------------------------------\n");
	printf("   FT_STRDUP:\n");
	printf("------------------------------------\n");

printf("------------------------\n");
printf("Test 1: Basic\n");
printf("------------------------\n");

	char	*src_dup1 = "Hello World!";
	char	*tst_dst_dup1;
	char	*sys_dst_dup1;

	tst_dst_dup1 = _ft_strdup(src_dup1);
	sys_dst_dup1 = strdup(src_dup1);

	printf("    SRC STR:	|%s|\n", src_dup1);
	printf("TST DST STR:	|%s|\n", tst_dst_dup1);
	printf("SYS DST STR:	|%s|\n", sys_dst_dup1);

printf("------------------------\n");
printf("Test 2: Empty Src\n");
printf("------------------------\n");

	char	*sys_dst_dup4;
	char	*tst_dst_dup4;

	tst_dst_dup4 = _ft_strdup("");
	sys_dst_dup4 = strdup("");

	printf("    SRC STR:	|%s|\n", "");
	printf("TST DST STR:	|%s|\n", tst_dst_dup4);
	printf("SYS DST STR:	|%s|\n", sys_dst_dup4);

printf("------------------------\n");
printf("Test 3: NULL Src\n");
printf("------------------------\n");

//	char	*sys_dst_dup5;
//	char	*tst_dst_dup5;
//
//	tst_dst_dup5 = _ft_strdup(0);
//	sys_dst_dup5 = strdup(0);
//
//	printf("    SRC STR:	|%s|\n", 0);
//	printf("TST DST STR:	|%s|\n", tst_dst_dup5);
//	printf("SYS DST STR:	|%s|\n", sys_dst_dup5);

printf("------------------------\n");
printf("Test 4: Long\n");
printf("------------------------\n");

	char	*src_dup6 = malloc (5000);
	char	*tst_dst_dup6;
	char	*sys_dst_dup6;

	for(int i = 0; i < 5000; i++)
	{
		src_dup6[i] = (rand() % 94) + 32;
	}
	src_dup6[4999] = '\0';

	tst_dst_dup6 = _ft_strdup(src_dup6);
	sys_dst_dup6 = strdup(src_dup6);

	printf("    SRC STR:	|%s|\n", src_dup6);
	printf("TST DST STR:	|%s|\n", tst_dst_dup6);
	printf("SYS DST STR:	|%s|\n", sys_dst_dup6);

printf("\n");

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
