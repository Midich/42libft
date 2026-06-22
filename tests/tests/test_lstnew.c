#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("ft_lstnew\t");

	t_list * l =  ft_lstnew((void*)42);
	/* 1 */ check(l->content == (void*)42);
	/* 2 */ check(l->next == 0);
	/* 3 */ mcheck(l, sizeof(t_list)); free(l);
	printf("\n");
}
