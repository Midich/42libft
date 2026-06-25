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

// helpers for itter
static void add_ten(void *content) {
    int *val = (int *)content;
    *val += 10;
}

int main(){
    printf("\n=====LSTITER=====\n");
    int arr[] = {1, 2, 3};
    t_list *list = list_from_array(arr, 3);

    ft_lstiter(list, add_ten);

    int expected[] = {11, 12, 13};
    t_list *cur = list;
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
    SOFT_ASSERT(ok && i == 3, "ft_lstiter failed to apply function");

    ft_lstiter(NULL, add_ten);
    SOFT_ASSERT(1 == 1, "ft_lstiter(NULL) did not crash");

    ft_lstclear(&list, free);
	print_summary();
}
