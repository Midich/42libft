/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:53:57 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/26 14:03:32 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*csrc = src;
	unsigned char		*cdest;
	const unsigned char	*lsrc = src + (n - 1);
	unsigned char		*ldest;

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
