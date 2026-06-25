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
    printf("\n=====LSTADD_BACK=====\n");
    t_list *list = NULL;
    t_list *node1 = create_node_int(1);
    t_list *node2 = create_node_int(2);
    t_list *node3 = create_node_int(3);

    ft_lstadd_back(&list, node1);
    SOFT_ASSERT(list == node1, "add_back to empty list failed");
    SOFT_ASSERT(list->next == NULL, "add_back to empty list: next not NULL");

    ft_lstadd_back(&list, node2);
    SOFT_ASSERT(list == node1, "add_back changed head");
    SOFT_ASSERT(list->next == node2, "add_back order wrong");
    SOFT_ASSERT(list->next->next == NULL, "add_back order wrong");

    ft_lstadd_back(&list, node3);
    SOFT_ASSERT(list->next->next == node3, "add_back order wrong");
    SOFT_ASSERT(list->next->next->next == NULL, "add_back order wrong");

    ft_lstclear(&list, free);
	print_summary();
}
