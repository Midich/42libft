/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:05:04 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/17 18:14:18 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*calloc(t_ulong nmemb, t_ulong size)
{
	if (!nmemb || !size)
		return (malloc(1));
	return (malloc(nmemb * size));
}
