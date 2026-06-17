/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:48:47 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/17 16:05:38 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cc;

	cc = c;
	while (1)
	{
		if (*s == cc)
			return ((char *)s);
		else if (*s == 0)
			return (0);
		s++;
	}
}
