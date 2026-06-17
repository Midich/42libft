/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:32:39 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/17 18:27:52 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

typedef unsigned long int	t_ulong;

// ctype functions
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

t_ulong	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, t_ulong n);
void	ft_bzero(void *s, t_ulong n);
void	*ft_memcpy(void *dest, const void *src, t_ulong n);
void	*ft_memmove(void *dest, const void *src, t_ulong n);
t_ulong	ft_strlcpy(char *dst, const char *src, t_ulong size);
t_ulong	ft_strlcat(char *dst, const char *src, t_ulong size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, t_ulong n);
void	*ft_memchr(const void *s, int c, t_ulong n);
int		ft_memcmp(const void *s1, const void *s2, t_ulong n);
char	*ft_strnstr(const char *big, const char *little, t_ulong len);
int		ft_atoi(const char *nptr);

void	*ft_calloc(t_ulong nmemb, t_ulong size);
char	*ft_strdup(const char *s);
#endif
