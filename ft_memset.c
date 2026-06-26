/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:52:18 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/26 17:38:11 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cast_s;
	unsigned char	cast_c;

	if (!s)
		return (0);
	cast_s = (unsigned char *)s;
	cast_c = (unsigned char)c;
	while (n)
	{
		n--;
		*(cast_s + n) = cast_c;
	}
	return (s);
}
