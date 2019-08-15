/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:49:05 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/27 17:54:02 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_list_push_back(t_list **begin_list, int fd);
t_list				*ft_lstnew(int fd);
t_list				*ft_list_find(t_list *begin_list, int fd);
void				ft_lstdel(t_list **begin);
void				ft_lstdelone(t_list **begin, t_list *to_del);

void				ft_list_foreach_if(t_list *begin_list,
		void (*f)(void *), void *content, int (*cmp)(void *, void *));
void				ft_list_reverse(t_list **begin_list);
char				*ft_strev(char *str);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
int					ft_atoi(const char *str);
void				*ft_memalloc(size_t size);
int					ft_isalnum(int c);
char				*ft_itoa(int n);
int					ft_isascii(int c);
void				*ft_memset(void *destination, int c, size_t n);
void				*ft_memmove(void *destination,
		const void *source, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *arr1, const void *arr2, size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
void				*ft_memccpy(void *destination,
		const void *source, int c, size_t n);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *destination, const char *source);
char				*ft_strdup(const char *str);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strncat(char *dst, const char *app, size_t n);
char				*ft_strcat(char *dst, const char *app);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
int					ft_toupper(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isprint(int c);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strdel(char **as);
char				*ft_strrchr(const char *str, int c);
void				ft_strclr(char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
void				ft_putchar(char c);
char				*ft_strstr(const char *str, const char *to_find);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);

#endif
