/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:32:39 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/16 14:47:29 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

// ctype functions
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

unsigned long int	ft_strlen(const char *s);
void				*ft_memset(void *s, int c, unsigned long int n);
void				ft_bzero(void *s, unsigned int n);
void				*ft_memcpy(void *dest,
						const void *src, unsigned long int n);
//ft_memmove
//ft_strlcpy
//ft_strlcat
//ft_toupper
//ft_tolower
//ft_strchr
//ft_strrchr
//ft_strncmp
//ft_memchr
//ft_memcmp
//ft_strnstr
//ft_atoi
#endif
