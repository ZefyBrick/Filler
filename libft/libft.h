/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 17:38:41 by cdubuque          #+#    #+#             */
/*   Updated: 2019/11/01 16:36:30 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *d, const void *s, size_t n);
void				*ft_memmove(void *d, const void *s, size_t n);
void				*ft_memset(void *dest, int c, size_t n);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncat(char *d, const char *s, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcat(char *d, const char *s);
size_t				ft_strlcat(char *d, const char *s, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_strclr(char *s);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_strdel(char **as);
char				*ft_itoa(int n);
void				ft_memdel(void **ap);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
int					ft_atoi(const char *s);
void				ft_bzero(void *s, size_t n);
int					ft_modul(char *mas);
void				*ft_memalloc(size_t size);
void				ft_first_free_join(char **s, char *p);
char				*ft_second_free_join(char *s, char *p);
char				*ft_free_strdup(char *s, size_t i);
char				*ft_free_sub(char const *s, unsigned int start, size_t len);
int					ft_while_digit(char *m);
int					ft_not_prob(char *m);
int					ft_len_digit(int n, int col);
int					ft_modul_int(int i);
int					ft_modul_int_change(int i, int num);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_split_free(char **tmp);
#endif
