/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:14:27 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/17 18:42:06 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	const t_ulong	s_len = ft_strlen(s);
	char			*new_string;
	t_ulong			i;

	i = 0;
	new_string = malloc(s_len + 1);
	while (s[i])
	{
		new_string[i] = s[i];
		i++;
	}
	new_string[i] = 0;
	return (new_string);
}
