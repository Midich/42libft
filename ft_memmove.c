/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:53:57 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/26 18:08:28 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*csrc = src;
	const unsigned char	*lsrc;
	unsigned char		*cdest;
	unsigned char		*ldest;

	if (n == 0)
		return (dest);
	lsrc = src + (n - 1);
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
