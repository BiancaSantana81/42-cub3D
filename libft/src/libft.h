/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:38:01 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/24 14:38:04 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 22
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_gnl
{
	char			c;
	struct s_gnl	*next;
}	t_gnl;

typedef struct s_find
{
	char	buffer[BUFFER_SIZE];
	int		pos;
	int		bytes;
}	t_find;

/*
********************************************************************************
								 LIB FUNCTIONS
*/
char		*ft_itoa(int n);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strndup(const char *s, size_t len);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		**ft_split(char const *s, char c);
char		**ft_special_split(char const *s);
int			ft_strstr(char *str, char *to_find);
int			ft_strnchr(char *str, char c, int len);
int			ft_atoi(const char *nptr);
int			ft_issign(char c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isspace(char c);
int			ft_isprint(int c);
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_printf_fd(int fd, const char *type_format, ...);
int			ft_flags(int fd, char flag, va_list args);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_free_matrix(char **matrix);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *ptr, int value, size_t num);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
size_t		ft_strcat(char *dst, const char *src);
size_t		ft_strcspn(char *s, char	*reject);
long int	ft_atol(const char *nptr);

/*
********************************************************************************
								LINKED LIST
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));

/*
********************************************************************************
								FT_PRINTF
*/

int			ft_printf(const char *print, ...);
int			ft_p_char(char c);
int			ft_p_string(char *str);
int			ft_p_int(long int n);
int			ft_p_unsigned(unsigned int n);
int			ft_p_lower_hex(unsigned int n);
int			ft_p_upper_hex(unsigned int n);
int			ft_p_address(unsigned long p);
int			ft_strlen_print(char *ptr);
char		*ft_strchr_print(const char *s, int c);

/*
*******************************************************************************
								GET NEXT LINE
*/

char		*get_next_line(int fd);
char		*ft_transform(t_gnl *root, int len);
void		ft_insert_end(t_gnl **root, char c);
void		ft_dealloc(t_gnl **root);
int			ft_build_line(t_find *file, t_gnl **root, int bytes);
int			ft_read_file(int fd, t_find *file, t_gnl **root);
int			ft_lstchr(t_gnl *root);

#endif
