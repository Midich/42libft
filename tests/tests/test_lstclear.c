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
    printf("\n=====LSTCLEAR=====\n");
    int arr[] = {1, 2, 3, 4, 5};
    t_list *list = list_from_array(arr, 5);
    SOFT_ASSERT(list != NULL, "ft_lstclear: list creation failed");

    ft_lstclear(&list, free);
    SOFT_ASSERT(list == NULL, "ft_lstclear did not set pointer to NULL");

    ft_lstclear(NULL, free);
	print_summary();
}

