#ifndef LIBASM_H
# define LIBASM_H

void		_ft_bzero(void *s, size_t len);
int 		_ft_isalnum(int c);
int 		_ft_isascii(int c);
int 		_ft_isalpha(int c);
int 		_ft_isdigit(int c);

ssize_t		_ft_read(int rd, void *buf, size_t count);
int			_ft_strcmp(const char *s1, const char *s2);
char		*_ft_strcpy(char *dst, const char *src);
char		*_ft_strdup(const char *s);
size_t		_ft_strlen(const char *s);
char		*_ft_strncpy(char *dst, const char *src, size_t len);
ssize_t		_ft_write(int fd, void *buf, size_t count);

#endif
