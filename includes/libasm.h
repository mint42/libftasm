#ifndef LIBASM_H
# define LIBASM_H

#include <stddef.h>
#include <sys/types.h>

int			ft_set_errno(int errno);
void		ft_bzero(void *s, size_t len);
int 		ft_isalnum(int c);
int 		ft_isascii(int c);
int 		ft_isalpha(int c);
int 		ft_isdigit(int c);

ssize_t		ft_read(int fd, void *buf, size_t count);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
char		*ft_strncpy(char *dst, const char *src, size_t len);
ssize_t		ft_write(int fd, void *buf, size_t count);

#endif
