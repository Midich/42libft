/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:52:18 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/17 16:22:45 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, t_ulong n)
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
