#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libasm.h"

int		main()
{

/*-------------------------------------------------
	ft_bzero
-------------------------------------------------*/
	printf("FT_BZERO:\n");
	printf("------------------------------------\n\n");
	char	array[10] = "1234567890";
	char	*to_malloc = malloc(10);

	write(1, array, 10);
	_ft_bzero(array, 10);
	write(1, array, 10);
	write(1, to_malloc, 10);
	_ft_bzero(to_malloc, 10);
	write(1, to_malloc, 10); printf("\n\n");

/*-------------------------------------------------
	ft_isalnum
-------------------------------------------------*/

	printf("FT_ISALNUM:\n\n");
	printf("------------------------------------\n\n");
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
	(_ft_isalnum('/')) ? "FAIL" : "PASS",
	(_ft_isalnum('0')) ? "PASS" : "FAIL",
	(_ft_isalnum('4')) ? "PASS" : "FAIL",
	(_ft_isalnum('9')) ? "PASS" : "FAIL",
	(_ft_isalnum(':')) ? "FAIL" : "PASS",
	(_ft_isalnum('@')) ? "FAIL" : "PASS",
	(_ft_isalnum('A')) ? "PASS" : "FAIL",
	(_ft_isalnum('K')) ? "PASS" : "FAIL",
	(_ft_isalnum('Z')) ? "PASS" : "FAIL",
	(_ft_isalnum('[')) ? "FAIL" : "PASS",
	(_ft_isalnum(96)) ? "FAIL" : "PASS",
	(_ft_isalnum('a')) ? "PASS" : "FAIL",
	(_ft_isalnum('K')) ? "PASS" : "FAIL",
	(_ft_isalnum('z')) ? "PASS" : "FAIL",
	(_ft_isalnum(123)) ? "FAIL" : "PASS",
	(_ft_isalnum(127)) ? "FAIL" : "PASS");
	printf("\n\n");

/*-------------------------------------------------
	ft_isalpha
-------------------------------------------------*/
	printf("FT_ISALPHA:\n\n");
	printf("------------------------------------\n\n");
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
	(_ft_isalpha('@')) ? "FAIL" : "PASS",
	(_ft_isalpha('A')) ? "PASS" : "FAIL",
	(_ft_isalpha('K')) ? "PASS" : "FAIL",
	(_ft_isalpha('Z')) ? "PASS" : "FAIL",
	(_ft_isalpha('[')) ? "FAIL" : "PASS",
	(_ft_isalpha(96)) ? "FAIL" : "PASS",
	(_ft_isalpha('a')) ? "PASS" : "FAIL",
	(_ft_isalpha('K')) ? "PASS" : "FAIL",
	(_ft_isalpha('z')) ? "PASS" : "FAIL",
	(_ft_isalpha(123)) ? "FAIL" : "PASS",
	(_ft_isalpha(127)) ? "FAIL" : "PASS");
	printf("\n\n");

/*-------------------------------------------------
	ft_isdigit
-------------------------------------------------*/
	printf("FT_ISDIGIT:\n\n");
	printf("------------------------------------\n\n");
	printf("%s\n%s\n%s\n%s\n%s\n",
	(_ft_isdigit('/')) ? "FAIL" : "PASS",
	(_ft_isdigit('0')) ? "PASS" : "FAIL",
	(_ft_isdigit('4')) ? "PASS" : "FAIL",
	(_ft_isdigit('9')) ? "PASS" : "FAIL",
	(_ft_isdigit(':')) ? "FAIL" : "PASS");
	printf("\n\n");

/*-------------------------------------------------
	ft_read
-------------------------------------------------*/
	printf("FT_READ:\n");
	printf("------------------------------------\n\n");
	char	buf[10];
	char	buf2[10000];
	int		fd;
	int		red;
	int		cur;

	fd = open("./file", O_RDONLY);
	printf("%d\n", (int)_ft_read(fd, buf, 10));
	close(fd);

	cur = 0;
	fd = open("./config.mk", O_RDONLY);
	while ((red = (int)_ft_read(fd, buf2 + cur, 100)))
	{
		printf("%d ", red);
		cur += red;
	}
	printf("\n\n");
	close(fd);

/*-------------------------------------------------
	ft_write
-------------------------------------------------*/
	printf("FT_WRITE:\n");
	printf("------------------------------------\n\n");
	_ft_write(1, buf, 10);
	_ft_write(1, buf2, 1266);
	printf("\n\n");

/*-------------------------------------------------
	ft_strcmp
-------------------------------------------------*/
	printf("FT_STRCMP:\n");
	printf("------------------------------------\n\n");
	char	st1[22] = "Spongebob Squarepants";
	char	st2[22] = "Spongeboa Squarepants";

	printf("%s\n", ((int)_ft_strcmp(st1, st2)) == 1 ? "PASS" : "FAIL");
	printf("%s\n", ((int)_ft_strcmp(st2, st1)) == -1 ? "PASS" : "FAIL");
	printf("\n\n");

/*-------------------------------------------------
	ft_strcpy
-------------------------------------------------*/
	printf("FT_STRCPY:\n");
	printf("------------------------------------\n\n");
	char	str[11] = "zzzzzzzzzz";
	printf("%s\n", _ft_strcpy(st1, str));
	printf("%s\n", st1);
	printf("%s\n", str);
	printf("\n");

/*-------------------------------------------------
	ft_strlen
-------------------------------------------------*/
	printf("FT_STRLEN:\n");
	printf("------------------------------------\n\n");
	char	str2[13] = "Patrick Star";
	printf("%s\n", str2);
	printf("%d\n", (int)_ft_strlen(str2));
	printf("%s\n", str2);
	printf("0\n");
	printf("%d\n", (int)_ft_strlen(0));
	printf("\n");

	return (0);
}
