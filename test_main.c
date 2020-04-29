#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libasm.h"

int main()
{

/*-------------------------------------------------
	ft_strlen
-------------------------------------------------*/

	printf("------------------------------------\n\n");
	printf("   FT_STRLEN:\n");
	printf("------------------------------------\n\n");

	size_t	tst_len;
	size_t	sys_len;

// t1 -> basic

	char	str[13] = "Hello World!\n";
	tst_len = _ft_strlen(str);
	sys_len = strlen(str);
	printf("STR:		|%s|\n", str);
	printf("len tst:	|%ld|\n", tst_len);
	printf("len sys:	|%ld|\n", sys_len);

	printf("\n");

// t2 -> empty

	tst_len = _ft_strlen("");
	sys_len = strlen("");
	printf("STR:		|%s|\n", "");
	printf("len tst:	|%s|\n", tst_len);
	printf("len sys:	|%s|\n", sys_len);

	printf("\n");

// t3 -> null

	tst_len = _ft_strlen(NULL);
	sys_len = strlen(NULL);
	printf("STR:		|%s|\n", "NULL");
	printf("len tst:	|%s|\n", tst_len);
	printf("len sys:	|%s|\n", sys_len);

	printf("\n");

// t4 -> long

	char	str2[50000];

	for(int i = 0; i < 50000; i++)
	{
		str2[i] = (rand() % 94) + 32;
	}
	str2[49999] = '\0';

	tst_len = _ft_strlen(str);
	sys_len = strlen(str);
	printf("STR:		|%s|\n", str2);
	printf("len tst:	|%ld|\n", tst_len);
	printf("len sys:	|%ld|\n", sys_len);

	printf("\n");

/*-------------------------------------------------
	ft_strcpy
-------------------------------------------------*/

	printf("------------------------------------\n\n");
	printf("   FT_STRCPY:\n");
	printf("------------------------------------\n\n");

// t1 -> basic

	char	src_cpy1[13] = "Hello World!\n";
	char	tst_dst_cpy1[13];
	char	sys_dst_cpy1[13];

	printf("Before:\n");
	printf("    SRC STR:	|%s|\n", src_cpy1);
	printf("TST DST STR:	|%s|\n", tst_dst_cpy1);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy1);

	tst_dst_cpy1 = _ft_strcpy(tst_dst_cpy1, src_cpy1);
	sys_dst_cpy1 = strcpy(sys_dst_cpy1, src_cpy1);

	printf("After:\n");
	printf("    SRC STR:	|%s|\n", src_cpy1);
	printf("TST DST STR:	|%s|\n", tst_dst_cpy1);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy1);

// t2 -> longer src

	char	src_cpy2[13] = "Hello World!\n";
	char	tst_dst_cpy2[11];
	char	sys_dst_cpy2[11];

	printf("Before:\n");
	printf("    SRC STR:	|%s|\n", src_cpy2);
	printf("TST DST STR:	|%s|\n", tst_dst_cpy2);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy2);

	tst_dst_cpy2 = _ft_strcpy(tst_dst_cpy2, src_cpy2);
	sys_dst_cpy2 = strcpy(sys_dst_cpy2, src_cpy2);

	printf("After:\n");
	printf("    SRC STR:	|%s|\n", src_cpy2);
	printf("TST DST STR:	|%s|\n", tst_dst_cpy2);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy2);

// t3 -> longer dst

	char	src_cpy3[13] = "Hello World!\n";
	char	tst_dst_cpy3[15];
	char	sys_dst_cpy3[15];

	printf("Before:\n");
	printf("    SRC STR:	|%s|\n", src_cpy3);
	printf("TST DST STR:	|%s|\n", tst_dst_cpy3);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy3);

	tst_dst_cpy3 = _ft_strcpy(tst_dst_cpy3, src_cpy3);
	sys_dst_cpy3 = strcpy(sys_dst_cpy3, src_cpy3);

	printf("After:\n");
	printf("    SRC STR:	|%s|\n", src_cpy3);
	printf("TST DST STR:	|%s|\n", tst_dst_cpy3);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy3);

// t4 -> empty src

	char	sys_dst_cpy4[13];
	char	tst_dst_cpy4[13];

	printf("Before:\n");
	printf("    SRC STR:	|%s|\n", "");
	printf("TST DST STR:	|%s|\n", tst_dst_cpy4);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy4);

	tst_dst_cpy4 = _ft_strcpy(tst_dst_cpy4, "");
	sys_dst_cpy4 = strcpy(sys_dst_cpy4, "");

	printf("After:\n");
	printf("    SRC STR:	|%s|\n", "");
	printf("TST DST STR:	|%s|\n", tst_dst_cpy4);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy4);

// t5 -> empty dst

	char	src_cpy4[13] = "Hello World!\n";

	printf("Before:\n");
	printf("    SRC STR:	|%s|\n", src_cpy4);
	printf("TST DST STR:	|%s|\n", "");
	printf("SYS DST STR:	|%s|\n", "");

	_ft_strcpy("", src_cpy4);
	strcpy("", src_cpy4);

	printf("After:\n");
	printf("    SRC STR:	|%s|\n", src_cpy4);
	printf("TST DST STR:	|%s|\n", "");
	printf("SYS DST STR:	|%s|\n", "");

// t6 -> NULL src

	char	sys_dst_cpy5[15];
	char	tst_dst_cpy5[15];

	printf("Before:\n");

	tst_dst_cpy5 = _ft_strcpy(tst_dst_cpy5, 0);
	sys_dst_cpy5 = strcpy(sys_dst_cpy5, 0);

	printf("After:\n");
	printf("    SRC STR:	|%s|\n", 0);
	printf("TST DST STR:	|%s|\n", tst_dst_cpy5);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy5);

// t7 -> NULL dst

	char	src_cpy5[15] = "Hello World!\n";

	printf("Before:\n");
	printf("    SRC STR:	|%s|\n", src_cpy5);
	printf("TST DST STR:	|%s|\n", 0);
	printf("SYS DST STR:	|%s|\n", 0);

	_ft_strcpy(0, src_cpy5);
	strcpy(0, src_cpy5);

	printf("After:\n");
	printf("    SRC STR:	|%s|\n", src_cpy5);
	printf("TST DST STR:	|%s|\n", 0);
	printf("SYS DST STR:	|%s|\n", 0);

// t8 -> long

	char	src_cpy_6[50000];
	char	tst_dst_cpy1[50000];
	char	sys_dst_cpy1[50000];

	for(int i = 0; i < 50000; i++)
	{
		src_cpy6[i] = (rand() % 94) + 32;
	}
	str2[49999] = '\0';

	printf("Before:\n");
	printf("    SRC STR:	|%s|\n", src_cpy6);
	printf("TST DST STR:	|%s|\n", tst_dst_cpy6);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy6);

	tst_dst_cpy6 = _ft_strcpy(tst_dst_cpy6, src_cpy6);
	sys_dst_cpy6 = strcpy(sys_dst_cpy6, src_cpy6);

	printf("After:\n");
	printf("    SRC STR:	|%s|\n", src_cpy6);
	printf("TST DST STR:	|%s|\n", tst_dst_cpy6);
	printf("SYS DST STR:	|%s|\n", sys_dst_cpy6);

	printf("\n");


/*-------------------------------------------------
	ft_strcmp
-------------------------------------------------*/

	printf("------------------------------------\n\n");
	printf("FT_STRCMP:\n");
	printf("------------------------------------\n\n");

// t1 -> basic

	char	src_cpy1[13] = "Hello World!";
	char	dst_cpy1[13] = "Hello Morld!";

	printf("SRC STR:	|%s|\n", src_cpy1);
	printf("DST STR:	|%s|\n", dst_cpy1);

	printf("tst cmp:	|%ld|\n", _ft_strcmp(dst_cpy1, src_cpy1));
	printf("sys cmp:	|%ld|\n", strcmp(dst_cpy1, src_cpy1));

// t2 -> longer src
	char	src_cpy2[15] = "Hello World!!!";

	printf("SRC STR:	|%s|\n", src_cpy2);
	printf("DST STR:	|%s|\n", dst_cpy1);

	printf("tst cmp:	|%ld|\n", _ft_strcmp(dst_cpy1, src_cpy2));
	printf("sys cmp:	|%ld|\n", strcmp(dst_cpy1, src_cpy2));

// t3 -> longer dst

	printf("SRC STR:	|%s|\n", dst_cpy1);
	printf("DST STR:	|%s|\n", src_cpy2);

	printf("tst cmp:	|%ld|\n", _ft_strcmp(src_cpy2, dst_cpy1));
	printf("sys cmp:	|%ld|\n", strcmp(src_cpy2, dst_cpy1));

// t4 -> empty src

	printf("SRC STR:	|%s|\n", "");
	printf("DST STR:	|%s|\n", src_cpy1);

	printf("tst cmp:	|%ld|\n", _ft_strcmp(src_cpy1, ""));
	printf("sys cmp:	|%ld|\n", strcmp(src_cpy1, ""));

// t5 -> empty dst

	printf("SRC STR:	|%s|\n", src_cpy1);
	printf("DST STR:	|%s|\n", "");

	printf("tst cmp:	|%ld|\n", _ft_strcmp("", src_cpy1));
	printf("sys cmp:	|%ld|\n", strcmp("", src_cpy1));

// t6 -> NULL src

	printf("SRC STR:	|%s|\n", 0);
	printf("DST STR:	|%s|\n", src_cpy1);

	printf("tst cmp:	|%ld|\n", _ft_strcmp(src_cpy1, 0));
	printf("sys cmp:	|%ld|\n", strcmp(src_cpy1, 0));

// t7 -> NULL dst

	printf("SRC STR:	|%s|\n", src_cpy1);
	printf("DST STR:	|%s|\n", 0);

	printf("tst cmp:	|%ld|\n", _ft_strcmp(0, src_cpy_1));
	printf("sys cmp:	|%ld|\n", strcmp(0, src_cpy1));

// t8 -> long

	char	src_cpy_6[10000];
	char	dst_cpy6[10000];

	for(int i = 0; i < 10000; i++)
	{
		src_cpy6[i] = (rand() % 94) + 32;
		if (i < 10000)
			dst_cpy6[i] = src_cpy6[i];
		else
			dst_cpy6[i] = '*';
	}
	str2[9999] = '\0';

	printf("SRC STR:	|%s|\n", src_cpy6);
	printf("DST STR:	|%s|\n", dst_cpy6);

	printf("tst cmp:	|%ld|\n", _ft_strcmp(dst_cpy6, src_cpy6));
	printf("sys cmp:	|%ld|\n", strcmp(dst_cpy6, src_cpy6));

	printf("\n");


/*-------------------------------------------------
	ft_strdup
-------------------------------------------------*/

	printf("------------------------------------\n\n");
	printf("   FT_STRDUP:\n");
	printf("------------------------------------\n\n");

// t1 -> basic

	char	src_dup1[13] = "Hello World!\n";
	char	tst_dst_dup1[13];
	char	sys_dst_dup1[13];

	printf("Before:\n");
	printf("    SRC STR:	|%s|\n", src_dup1);
	printf("TST DST STR:	|%s|\n", tst_dst_dup1);
	printf("SYS DST STR:	|%s|\n", sys_dst_dup1);

	tst_dst_dup1 = _ft_strdup(tst_dst_dup1, src_dup1);
	sys_dst_dup1 = strdup(sys_dst_dup1, src_dup1);

	printf("After:\n");
	printf("    SRC STR:	|%s|\n", src_dup1);
	printf("TST DST STR:	|%s|\n", tst_dst_dup1);
	printf("SYS DST STR:	|%s|\n", sys_dst_dup1);

// t2 -> longer src

	char	src_dup2[13] = "Hello World!\n";
	char	tst_dst_dup2[11];
	char	sys_dst_dup2[11];

	printf("Before:\n");
	printf("    SRC STR:	|%s|\n", src_dup2);
	printf("TST DST STR:	|%s|\n", tst_dst_dup2);
	printf("SYS DST STR:	|%s|\n", sys_dst_dup2);

	tst_dst_dup2 = _ft_strdup(tst_dst_dup2, src_dup2);
	sys_dst_dup2 = strdup(sys_dst_dup2, src_dup2);

	printf("After:\n");
	printf("    SRC STR:	|%s|\n", src_dup2);
	printf("TST DST STR:	|%s|\n", tst_dst_dup2);
	printf("SYS DST STR:	|%s|\n", sys_dst_dup2);

// t3 -> longer dst

	char	src_dup3[13] = "Hello World!\n";
	char	tst_dst_dup3[15];
	char	sys_dst_dup3[15];

	printf("Before:\n");
	printf("    SRC STR:	|%s|\n", src_dup3);
	printf("TST DST STR:	|%s|\n", tst_dst_dup3);
	printf("SYS DST STR:	|%s|\n", sys_dst_dup3);

	tst_dst_dup3 = _ft_strdup(tst_dst_dup3, src_dup3);
	sys_dst_dup3 = strdup(sys_dst_dup3, src_dup3);

	printf("After:\n");
	printf("    SRC STR:	|%s|\n", src_dup3);
	printf("TST DST STR:	|%s|\n", tst_dst_dup3);
	printf("SYS DST STR:	|%s|\n", sys_dst_dup3);

// t4 -> empty src

	char	sys_dst_dup4[13];
	char	tst_dst_dup4[13];

	printf("Before:\n");
	printf("    SRC STR:	|%s|\n", "");
	printf("TST DST STR:	|%s|\n", tst_dst_dup4);
	printf("SYS DST STR:	|%s|\n", sys_dst_dup4);

	tst_dst_dup4 = _ft_strdup(tst_dst_dup4, "");
	sys_dst_dup4 = strdup(sys_dst_dup4, "");

	printf("After:\n");
	printf("    SRC STR:	|%s|\n", "");
	printf("TST DST STR:	|%s|\n", tst_dst_dup4);
	printf("SYS DST STR:	|%s|\n", sys_dst_dup4);

// t5 -> empty dst

	char	src_dup4[13] = "Hello World!\n";

	printf("Before:\n");
	printf("    SRC STR:	|%s|\n", src_dup4);
	printf("TST DST STR:	|%s|\n", "");
	printf("SYS DST STR:	|%s|\n", "");

	_ft_strdup("", src_dup4);
	strdup("", src_dup4);

	printf("After:\n");
	printf("    SRC STR:	|%s|\n", src_dup4);
	printf("TST DST STR:	|%s|\n", "");
	printf("SYS DST STR:	|%s|\n", "");

// t6 -> NULL src

	char	sys_dst_dup5[15];
	char	tst_dst_dup5[15];

	printf("Before:\n");

	tst_dst_dup5 = _ft_strdup(tst_dst_dup5, 0);
	sys_dst_dup5 = strdup(sys_dst_dup5, 0);

	printf("After:\n");
	printf("    SRC STR:	|%s|\n", 0);
	printf("TST DST STR:	|%s|\n", tst_dst_dup5);
	printf("SYS DST STR:	|%s|\n", sys_dst_dup5);

// t7 -> NULL dst

	char	src_dup5[15] = "Hello World!\n";

	printf("Before:\n");
	printf("    SRC STR:	|%s|\n", src_dup5);
	printf("TST DST STR:	|%s|\n", 0);
	printf("SYS DST STR:	|%s|\n", 0);

	_ft_strdup(0, src_dup5);
	strdup(0, src_dup5);

	printf("After:\n");
	printf("    SRC STR:	|%s|\n", src_dup5);
	printf("TST DST STR:	|%s|\n", 0);
	printf("SYS DST STR:	|%s|\n", 0);

// t8 -> long

	char	src_dup_6[50000];
	char	tst_dst_dup1[50000];
	char	sys_dst_dup1[50000];

	for(int i = 0; i < 50000; i++)
	{
		src_dup6[i] = (rand() % 94) + 32;
	}
	str2[49999] = '\0';

	printf("Before:\n");
	printf("    SRC STR:	|%s|\n", src_dup6);
	printf("TST DST STR:	|%s|\n", tst_dst_dup6);
	printf("SYS DST STR:	|%s|\n", sys_dst_dup6);

	tst_dst_dup6 = _ft_strdup(tst_dst_dup6, src_dup6);
	sys_dst_dup6 = strdup(sys_dst_dup6, src_dup6);

	printf("After:\n");
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

	/*_ft_strdup---------------*/

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
