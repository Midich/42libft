/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:46:04 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/17 18:24:03 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	acc;

	acc = 0;
	neg = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*(nptr++) == '-')
			neg = -1;
	}
	while (*nptr || ft_isdigit(*nptr))
	{
		acc += *(nptr++) - '0';
	}
	return (acc * neg);
}
