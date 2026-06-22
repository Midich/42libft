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

void addOne(void * p)
{
	++*(int*)p;
}

int main()
{
	printf("ft_lstiter\t");

	int tab[] = {0, 1, 2, 3};
	t_list * l =  ft_lstnew(tab);
	for (int i = 1; i < 4; ++i)
		ft_lstadd_back(&l, ft_lstnew(tab + i));
	ft_lstiter(l, addOne);
	t_list * tmp = l;
	/* 1 2 3 4 */ for (int i = 0; i < 4; ++i)
	{
		check(*(int*)tmp->content == i + 1);
		tmp = (t_list *)tmp->next;
	}
	freeList(l);
	printf("\n");
}
