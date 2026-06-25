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

static t_list *list_from_array(int *arr, int size) {
    t_list *head = NULL;
    t_list *tail = NULL;
    for (int i = 0; i < size; i++) {
        t_list *node = create_node_int(arr[i]);
        if (!node) {
            ft_lstclear(&head, delete_int);
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
    printf("\n=====LSTSIZE=====\n");
    int arr1[] = {1, 2, 3};
    t_list *list1 = list_from_array(arr1, 3);
    SOFT_ASSERT(ft_lstsize(list1) == 3, "ft_lstsize with 3 nodes failed");

    int arr2[] = {42};
    t_list *list2 = list_from_array(arr2, 1);
    SOFT_ASSERT(ft_lstsize(list2) == 1, "ft_lstsize with 1 node failed");

    t_list *list3 = NULL;
    SOFT_ASSERT(ft_lstsize(list3) == 0, "ft_lstsize with NULL failed");

    ft_lstclear(&list1, delete_int);
    ft_lstclear(&list2, delete_int);
    print_summary();
}
