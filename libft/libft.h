/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:43:46 by yhsu              #+#    #+#             */
/*   Updated: 2024/03/13 13:31:30 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
//memory
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t n);
void	*ft_memchr(void const *str, int c, size_t n);
int		ft_memcmp(void const *s1, const void	*s2, size_t n);
void	*ft_memcpy(void	*dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
//print
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
//string
int		ft_atoi(const char	*str);
char	*ft_itoa(int n);
void	ft_free_split(char **result);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char	*str, int c);
char	*ft_strdup(const char	*s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const	*s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
size_t	ft_strlcpy(char *dest, const char	*src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(const char	*s, char (*f)(unsigned int, char));
int		ft_strncmp(const char	*s1, const char	*s2, size_t n);
char	*ft_strnstr(const char	*haystack, const char	*needle, size_t n);
char	*ft_strrchr(const char	*str, int c);
char	*ft_strtrim(const char	*s1, char const *set);
char	*ft_substr(const char	*s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
//linked lists
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
#endif