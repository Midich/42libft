#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>

static t_list *create_node_int(int value) {
    int *content = malloc(sizeof(int));
    if (!content) return NULL;
    *content = value;
    return ft_lstnew(content);
}

int main(){
    printf("\n=====LSTDELONE=====\n");

    t_list *node1 = create_node_int(1);
    t_list *node2 = create_node_int(2);
    node1->next = node2;

    ft_lstdelone(node1, free);

    SOFT_ASSERT(node2->next == NULL, "ft_lstdelone modified next of next node");
    SOFT_ASSERT(*(int *)node2->content == 2, "ft_lstdelone corrupted next node");

    free(node2->content);
    free(node2);
	print_summary();
}

