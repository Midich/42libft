/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:17:15 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/18 15:36:14 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_delimiters(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*(s++) == c)
			i++;
	}
	return (i);
}

static void	free_list(char ***list, size_t count)
{
	while (count--)
		free((**list) + count);
	free(*list);
}

char	**ft_split(const char *s, char c)
{
	const size_t	list_len = count_delimiters(s, c) + 2;
	size_t			i;
	const char		*next_deli;
	char			**list;

	list = ft_calloc(list_len, sizeof(char *));
	if (!list)
		return (0);
	i = 0;
	while (i < list_len - 1)
	{
		next_deli = ft_strchr(s, c);
		if (!next_deli)
			next_deli = s + ft_strlen(s);
		list[i] = ft_substr(s, 0, next_deli - s);
		if (!list[i])
			return (free_list(&list, i), (void *) 0);
		i++;
		s = next_deli + 1;
	}
	list[i] = 0;
	return (list);
}
