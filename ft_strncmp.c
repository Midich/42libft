/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:09:30 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/17 17:06:15 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strncmp(const char *s1, const char *s2, t_ulong n)
{
	int	diff;

	if (n == 0)
		return (0);
	while (n-- && *s1 && *s2)
	{
		diff = *(s1++) - *(s2++);
		if (diff)
		{
			return (diff);
		}
	}
	return (*s1 - *s2);
}
