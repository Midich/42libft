#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>

static t_list *create_node_int(int value) {
    int *content = malloc(sizeof(int));
    if (!content) return NULL;
    *content = value;
    return ft_lstnew(content);
}

// linked list from int array
static t_list *list_from_array(int *arr, int size) {
    t_list *head = NULL;
    t_list *tail = NULL;
    for (int i = 0; i < size; i++) {
        t_list *node = create_node_int(arr[i]);
        if (!node) {
            ft_lstclear(&head, free);
            return NULL;
        }
        if (!head)
            head = node;
        else
            tail->next = node;
        tail = node;
    }
    return head;
}

int main(){
    printf("\n=====LSTLAST=====\n");
    int arr[] = {1, 2, 3, 4};
    t_list *list = list_from_array(arr, 4);
    t_list *last = ft_lstlast(list);
    SOFT_ASSERT(last != NULL, "ft_lstlast returned NULL for non-empty list");
    SOFT_ASSERT(*(int *)last->content == 4, "ft_lstlast wrong node");

    /* Single node */
    t_list *single = create_node_int(99);
    SOFT_ASSERT(ft_lstlast(single) == single, "ft_lstlast with single node failed");

    /* Empty list */
    SOFT_ASSERT(ft_lstlast(NULL) == NULL, "ft_lstlast with NULL should return NULL");

    ft_lstclear(&list, free);
    free(single->content);
    free(single);
	print_summary();
}

