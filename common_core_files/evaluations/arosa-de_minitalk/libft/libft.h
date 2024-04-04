/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:20:50 by arosa-de          #+#    #+#             */
/*   Updated: 2024/01/18 01:15:37 by arosa-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//entender
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

// entender mais
//	MAX_FILES_OPENED is the locked-in-memory size
//	obtained through the command "ulimit -a"
# ifndef MAX_FILES_OPENED
#  define MAX_FILES_OPENED 65536
# endif

//entender
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// FUNCTIONS
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);

// ADDITIONAL FUNCTIONS
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);

// BONUS
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// EXTRA
int		ft_issign(char c);
int		ft_format(va_list args, char specification);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_print_hex(unsigned int n, int c);
long	ft_atoi_long(const char *s);
//static int ft_tot(int n);
//static int ft_count(int n);
int		ft_putnbr(int n, int fd);
int		ft_putstr(char *s);
int		ft_length_pointer(uintptr_t n);
void	ft_ptr(uintptr_t ptr);
int		ft_print_pointer(unsigned long long ptr);
//static unsigned int unsig_number(unsigned int n);
int		ft_print_unsig(unsigned int n, int fd);
int		ft_issign(char c);
//static int read_buffer(int fd, char **stash, char *buffer);
//static void remove_result(char **stash);
//static void get_result(char **stash, char **result);
char	*get_next_line(int fd);

#endif
