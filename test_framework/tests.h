#ifndef TESTS_H
# define TESTS_H

# define N_FUNCS 12
# define MAX_TESTS 10

struct s_test_wrap;

void	load_tests_ft_bzero(struct s_test_wrap *func);
// {{{
int		ft_bzero_test_1(void);
int		ft_bzero_test_2(void);
int		ft_bzero_test_3(void);
int		ft_bzero_test_4(void);
int		ft_bzero_test_5(void);
int		ft_bzero_test_6(void);
// }}}

void	load_tests_ft_isascii(struct s_test_wrap *func);
// {{{
int		ft_isascii_test_1(void);
int		ft_isascii_test_2(void);
int		ft_isascii_test_3(void);
int		ft_isascii_test_4(void);
int		ft_isascii_test_5(void);
// }}}

void	load_tests_ft_isalnum(struct s_test_wrap *func);
// {{{
int		ft_isalnum_test_1(void);
int		ft_isalnum_test_2(void);
int		ft_isalnum_test_3(void);
int		ft_isalnum_test_4(void);
int		ft_isalnum_test_5(void);
// }}}

void	load_tests_ft_isalpha(struct s_test_wrap *func);
// {{{
int		ft_isalpha_test_1(void);
int		ft_isalpha_test_2(void);
int		ft_isalpha_test_3(void);
int		ft_isalpha_test_4(void);
int		ft_isalpha_test_5(void);
// }}}

void	load_tests_ft_isdigit(struct s_test_wrap *func);
// {{{
int		ft_isdigit_test_1(void);
int		ft_isdigit_test_2(void);
int		ft_isdigit_test_3(void);
int		ft_isdigit_test_4(void);
int		ft_isdigit_test_5(void);
// }}}

void	load_tests_ft_strlen(struct s_test_wrap *func);
// {{{
int		ft_strlen_test_1(void);
int		ft_strlen_test_2(void);
int		ft_strlen_test_3(void);
int		ft_strlen_test_4(void);
int		ft_strlen_test_5(void);
// }}}

void	load_tests_ft_strcpy(struct s_test_wrap *func);
// {{{
int		ft_strcpy_test_1(void);
int		ft_strcpy_test_2(void);
int		ft_strcpy_test_3(void);
int		ft_strcpy_test_4(void);
int		ft_strcpy_test_5(void);
int		ft_strcpy_test_6(void);
int		ft_strcpy_test_7(void);
int		ft_strcpy_test_8(void);
int		ft_strcpy_test_9(void);
int		ft_strcpy_test_10(void);
// }}}

void	load_tests_ft_strncpy(struct s_test_wrap *func);
// {{{
int		ft_strncpy_test_1(void);
int		ft_strncpy_test_2(void);
int		ft_strncpy_test_3(void);
int		ft_strncpy_test_4(void);
int		ft_strncpy_test_5(void);
int		ft_strncpy_test_6(void);
int		ft_strncpy_test_7(void);
int		ft_strncpy_test_8(void);
int		ft_strncpy_test_9(void);
int		ft_strncpy_test_10(void);
// }}}

void	load_tests_ft_strcmp(struct s_test_wrap *func);
// {{{
int		ft_strcmp_test_1(void);
int		ft_strcmp_test_2(void);
int		ft_strcmp_test_3(void);
int		ft_strcmp_test_4(void);
int		ft_strcmp_test_5(void);
int		ft_strcmp_test_6(void);
int		ft_strcmp_test_7(void);
int		ft_strcmp_test_8(void);
int		ft_strcmp_test_9(void);
int		ft_strcmp_test_10(void);
// }}}

void	load_tests_ft_strdup(struct s_test_wrap *func);
// {{{
int		ft_strdup_test_1(void);
int		ft_strdup_test_2(void);
int		ft_strdup_test_3(void);
int		ft_strdup_test_4(void);
int		ft_strdup_test_5(void);
// }}}

void	load_tests_ft_read(struct s_test_wrap *func);
// {{{
int		ft_read_test_1(void);
int		ft_read_test_2(void);
int		ft_read_test_3(void);
int		ft_read_test_4(void);
int		ft_read_test_5(void);
int		ft_read_test_6(void);
int		ft_read_test_7(void);
int		ft_read_test_8(void);
int		ft_read_test_9(void);
// }}}

void	load_tests_ft_write(struct s_test_wrap *func);
// {{{
int		ft_write_test_1(void);
int		ft_write_test_2(void);
int		ft_write_test_3(void);
int		ft_write_test_4(void);
int		ft_write_test_5(void);
int		ft_write_test_6(void);
int		ft_write_test_7(void);
int		ft_write_test_8(void);
int		ft_write_test_9(void);
// }}}

#endif

// vim: foldmarker={{{,}}} foldmethod=marker
