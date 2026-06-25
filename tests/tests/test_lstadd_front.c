#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>

static t_list *create_node_int(int value) {
    int *content = malloc(sizeof(int));
    if (!content) return NULL;
    *content = value;
    return ft_lstnew(content);
}

static void delete_int(void *content) {
    free(content);
}

int main() {
    printf("\n=====LSTADD_FRONT=====\n");
    t_list *list = NULL;
    t_list *node1 = create_node_int(1);
    t_list *node2 = create_node_int(2);

    ft_lstadd_front(&list, node1);
    SOFT_ASSERT(list == node1, "add_front to empty list failed");
    SOFT_ASSERT(list->next == NULL, "add_front to empty list: next not NULL");

    ft_lstadd_front(&list, node2);
    SOFT_ASSERT(list == node2, "add_front to non-empty list failed");
    SOFT_ASSERT(list->next == node1, "add_front order wrong");
    SOFT_ASSERT(list->next->next == NULL, "add_front order wrong");

    ft_lstclear(&list, delete_int);
	print_summary();
}
