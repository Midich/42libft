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

void	*ft_calloc(t_ulong nmemb, t_ulong size)
{
	void	*ptr;
	t_ulong	to_allocate;

	if (!nmemb || !size)
		return (malloc(1));
	to_allocate = nmemb * size;
	if (to_allocate / nmemb != size)
		return 0;
	ptr = malloc(to_allocate);
	if (ptr)
		ft_bzero(ptr, to_allocate);
	return (ptr);
}
