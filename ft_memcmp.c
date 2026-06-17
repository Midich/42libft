/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:58:53 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/17 17:05:05 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, t_ulong n)
{
	const unsigned char	*char_s1 = s1;
	const unsigned char	*char_s2 = s2;
	int					diff;	

	while (n--)
	{
		diff = *(char_s1++) - *(char_s2++);
		if (diff)
			return (diff);
	}
	return (0);
}
