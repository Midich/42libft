#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>

int main(){
    printf("\n=====STRDUP=====\n");
    const char *strs[] = {"", "a", "hello world", "12345"};
    for (size_t i = 0; i < sizeof(strs)/sizeof(strs[0]); i++) {
        const char *s = strs[i];
        char *dup1 = ft_strdup(s);
        char *dup2 = strdup(s);
        if (dup1 == NULL || dup2 == NULL) {
            /* Both should be NULL if allocation fails (unlikely) */
            SOFT_ASSERT(dup1 == dup2, "strdup NULL mismatch");
        } else {
            SOFT_ASSERT(strcmp(dup1, dup2) == 0,
                        "ft_strdup content mismatch");
            SOFT_ASSERT(ft_strlen(dup1) == strlen(dup2),
                        "ft_strdup length mismatch");
            free(dup1);
            free(dup2);
        }
    }
    print_summary();
}
