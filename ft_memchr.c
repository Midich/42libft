/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:53:04 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/26 17:31:51 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*char_s = s;
	unsigned char		char_c;
	
	if (!s)
		return (0);
	char_c = c;
	while (n--)
	{
		if (*char_s == char_c)
			return ((void *)char_s);
		char_s++;
	}
	return (0);
}
