#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void freeList(t_list *head)
{
	if (head)
		freeList((t_list *)head->next);
	free(head);
}

int main()
{
	printf("ft_lstadd_front\t");

	t_list * l =  NULL;
	ft_lstadd_front(&l, ft_lstnew((void*)1));
	/* 1 */ check(l->content == (void*)1);
	/* 2 */ check(l->next == 0);

	ft_lstadd_front(&l, ft_lstnew((void*)2));
	/* 3 */ check(l->content == (void*)2);
	/* 4 */ check(((t_list *)l->next)->content == (void*)1);
	/* 5 */ check(((t_list *)l->next)->next == 0);
	freeList(l);
	printf("\n");
}
