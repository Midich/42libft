#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>

// new node with integer
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

static void *multiply_by_2(void *content) {
    int *new = malloc(sizeof(int));
    if (!new)
        return NULL;
    *new = (*(int *)content) * 2;
    return new;
}

int main(){
    printf("\n=====LSTMAP=====\n");
    int arr[] = {1, 2, 3, 4};
    t_list *list = list_from_array(arr, 4);

    t_list *new_list = ft_lstmap(list, multiply_by_2, free);
    SOFT_ASSERT(new_list != NULL, "ft_lstmap returned NULL");
    int expected[] = {2, 4, 6, 8};
    t_list *cur = new_list;
    int i = 0;
    int ok = 1;
    while (cur) {
        if (*(int *)cur->content != expected[i]) {
            ok = 0;
            break;
        }
        cur = cur->next;
        i++;
    }
    SOFT_ASSERT(ok && i == 4, "ft_lstmap content mismatch");

    cur = list;
    int orig[] = {1, 2, 3, 4};
    i = 0;
    ok = 1;
    while (cur) {
        if (*(int *)cur->content != orig[i]) {
            ok = 0;
            break;
        }
        cur = cur->next;
        i++;
    }
    SOFT_ASSERT(ok && i == 4, "ft_lstmap modified original list");

    t_list *empty = NULL;
    t_list *new_empty = ft_lstmap(empty, multiply_by_2, free);
    SOFT_ASSERT(new_empty == NULL, "ft_lstmap with NULL should return NULL");

    //t_list *fail_list = list_from_array(arr, 4);
    //t_list *result = ft_lstmap(fail_list, map_fail_on_3, delete_int);
    //TEST_ASSERT(result == NULL, "ft_lstmap should return NULL when mapping fails");

    // cur = fail_list;
    // i = 0;
    // ok = 1;
    // while (cur) {
    //     if (*(int *)cur->content != orig[i]) {
    //         ok = 0;
    //         break;
    //     }
    //     cur = cur->next;
    //     i++;
    // }
    // TEST_ASSERT(ok && i == 4, "ft_lstmap modified original list on failure");

    ft_lstclear(&list, free);
    ft_lstclear(&new_list, free);
    // ft_lstclear(&fail_list, delete_int);
	print_summary();
}
