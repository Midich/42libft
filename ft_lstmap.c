/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:29:53 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/19 14:10:05 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*s_new;
	t_list	*temp;

	if (!lst)
		return (0);
	temp = ft_lstnew(f(lst->content));
	if (!temp)
		return (0);
	new = temp;
	s_new = temp;
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&s_new, del);
			return (0);
		}
		new->next = temp;
		new = temp;
		lst = lst->next;
	}
	return (s_new);
}
