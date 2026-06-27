#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>

int main() {
    printf("\n=====LSTNEW MALLOC FAIL=====\n");
    t_list *node = ft_lstnew(0);
    SOFT_ASSERT(node == NULL, "ft_lstnew should returned NULL");
	if (node)
	{
		free(node);
	}
	print_summary();
}
