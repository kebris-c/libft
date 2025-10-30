/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:29:26 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/29 16:23:43 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# include "get_next_line.h"
# include "ft_abs.h"
# include "ft_boolean.h"
# include "ft_point.h"
# include "ft_printf.h"
# include "ft_stock_str.h"

/* *** STRUCTURES, TYPEDEFS & DEFINES *** */

# define ATOI_BASE_ERROR INT_MIN
# define HEX "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"
# define DEC "0123456789"

typedef int	t_bool;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* *** CHARACTER FUNCTIONS *** */

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

/* *** MEMORY FUNCTIONS *** */

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_print_memory(void *addr, int size);

/* *** STRING FUNCTIONS *** */

char	*ft_strcapitalize(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strchr(const char *str, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strlowcase(char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *dest, char *src, unsigned int nb);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strupcase(char *str);
char	*ft_substr(char const *str, size_t start, size_t len);
t_bool	ft_is_sep(char c, char *charset);
char	**ft_split(char const *s, char c);

/* *** STRING VERIFICATION FUNCTIONS *** */

int		ft_str_is_alpha(char *str);
int		ft_str_is_lowercase(char *str);
int		ft_str_is_numeric(char *str);
int		ft_str_is_printable(char *str);
int		ft_str_is_uppercase(char *str);

/* *** NUMERIC AND MATHEMATICAL FUNCTIONS *** */

int		ft_atoi(const char *str);
int		ft_atoi_base(char *nbr, char *base);
void	ft_div_mod(int a, int b, int *div, int *mod);
int		ft_fibonacci(int index);
int		ft_find_next_prime(int nb);
t_bool	ft_is_even(int nbr);
int		ft_is_prime(int nb);
int		ft_iterative_factorial(int nb);
int		ft_iterative_power(int nb, int power);
char	*ft_itoa(int n);
char	*ft_itoa_base(int nb, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_recursive_factorial(int nb);
int		ft_recursive_power(int nb, int power);
int		ft_sqrt(int nb);
void	ft_swap(int *a, int *b);
void	ft_ultimate_div_mod(int *a, int *b);
t_bool	ft_incorrect_base(char *base);

/* *** OUTPUT FUNCTIONS *** */

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr(int nbr);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr_non_printable(char *str);

/* *** ARRAY FUNCTIONS *** */

void	ft_free_matrix(char **arr);
int		*ft_range(int min, int max);
void	ft_rev_int_tab(int *tab, int size);
void	ft_sort_int_tab(int *tab, int size);
int		ft_ultimate_range(int **range, int min, int max);

/* *** STRUCTURE FUNCTIONS *** */

void	ft_set_point(t_point *point, int a, int b);
void	ft_show_tab(struct s_stock_str *par);

/* *** LINKED LIST FUNCTIONS *** */

void	ft_lstadd_back(t_list **lst, t_list *node);
void	ft_lstadd_front(t_list **lst, t_list *node);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

/* *** FILE FUNCTIONS *** */

int		ft_check_open_read_close(ssize_t bytes_read, int fd);
int		ft_display_file(char *filename, size_t size);

/* *** SPECIFIC PROBLEM FUNCTIONS *** */

void	ft_n_queens_puzzle(int n);
void	ft_print_combn(int n);
void	ft_teen_queens_puzzle(void);

#endif
