/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:05:01 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/17 16:08:57 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*p = s;
	unsigned char	cc;

	cc = c;
	while (*p++)
		;
	while (1)
	{
		if (*p == cc)
			return ((char *)s);
		else if (p == s)
			return (0);
		p--;
	}
}
