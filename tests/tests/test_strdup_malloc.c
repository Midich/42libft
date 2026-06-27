#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>

int main(){
    printf("\n=====STRDUP MALLOC FAIL=====\n");
    const char *strs[] = {"", "a", "hello world", "12345"};
    for (size_t i = 0; i < sizeof(strs)/sizeof(strs[0]); i++) {
        const char *s = strs[i];
        char *dup1 = ft_strdup(s);
        /* Both should be NULL if allocation fails (unlikely) */
        SOFT_ASSERT(dup1 == NULL, "ft_strdup should retunred NULL");
    	if (dup1)
			free(dup1);
	}
    print_summary();
}
