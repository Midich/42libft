/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:53:57 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/17 16:22:21 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, t_ulong n)
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
