#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>

int main() {
    printf("\n=====LSTNEW=====\n");
    int *content = malloc(sizeof(int));
    *content = 42;
    t_list *node = ft_lstnew(content);
    SOFT_ASSERT(node != NULL, "ft_lstnew returned NULL");
    SOFT_ASSERT(node->content == content, "ft_lstnew content not set correctly");
    SOFT_ASSERT(*(int *)node->content == 42, "ft_lstnew content value mismatch");
    SOFT_ASSERT(node->next == NULL, "ft_lstnew next not NULL");
    free(node->content);
    free(node);
    print_summary();
}
