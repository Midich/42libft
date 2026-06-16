/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:28:13 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/16 15:29:23 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned long int	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (*s++)
	{
		len++;
	}
	return (len);
}

void	*ft_memset(void *s, int c, unsigned long int n)
{
	unsigned char	*cast_s;

	cast_s = (unsigned char *)s;
	while (n)
	{
		n--;
		*(cast_s + n) = c;
	}
	return (s);
}

void	ft_bzero(void *s, unsigned long int n)
{
	unsigned char	*cast_s;

	cast_s = (unsigned char *)s;
	while (n)
	{
		n--;
		*(cast_s + n) = 0;
	}
}

void	*ft_memcpy(void *dest, const void *src, unsigned long int n)
{
	char		*cdest;
	const char	*csrc = (char *)src;

	cdest = (char *)dest;
	while (n)
	{
		n--;
		*cdest++ = *csrc++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, unsigned long int n)
{
	const char	*csrc = src;
	char		*cdest;
	const char	*lsrc = src + (n - 1);
	char		*ldest;

	cdest = dest;
	ldest = dest + (n - 1);
	if (dest < src)
	{
		while (n--)
		{
			*cdest++ = *csrc++;
		}
	}
	else
	{
		while (n--)
		{
			*ldest-- = *lsrc--;
		}
	}
	return (dest);
}
