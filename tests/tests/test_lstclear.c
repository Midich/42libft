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
	printf("ft_lstclear\t");

	t_list * l =  ft_lstnew(malloc(1));
	for (int i = 0; i < 10; ++i)
		ft_lstadd_front(&l, ft_lstnew(malloc(1)));
	ft_lstclear(&l, free);
	/* 1 */ check(l == 0);
	/* 2 All other checks are done by valgrind */
	printf("\n");
}
