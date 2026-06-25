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
	printf("ft_lstdelone\t");

	t_list * l =  ft_lstnew(malloc(1));
	ft_lstdelone(l, free); l = 0;
	printf("\n");
}
