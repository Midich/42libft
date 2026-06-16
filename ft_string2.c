/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:21:26 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/16 15:59:09 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned long int	ft_strlcpy(char *dst, const char *src,
	unsigned long int size)
{
	const char			*ssrc = src;
	unsigned long int	left;

	left = size;
	if (left != 0)
	{
		while (--left)
		{
			if ((*dst++ = *src++) == 0)
				break;
		}
	}
	if (left == 0)
	{
		if (size != 0)
			*dst = 0;
		while(*src++);
	}
	return (src - ssrc - 1);
}
unsigned long int	ft_strlcat(char *dst, const char *src,
	unsigned long int size)
{
	unsigned long int	dst_len;
	unsigned long int	src_len;
	unsigned long int	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (size + src_len);
	i = 0;
	while (src[i] && i < (size - dest_len - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

int	toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c & 0x5f);
	return (c);	
}

int	tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c | 32);
	return c;
}
