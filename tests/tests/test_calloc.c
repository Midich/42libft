#include "../soft_assert.h"
#include "libft.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("\n=====CALLOC=====\n");
    /* Test with various count, size combinations */
    size_t tests[][2] = {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}, {5, 10}, {10, 5}, {100, 1}
    };
    for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        size_t count = tests[i][0];
        size_t size = tests[i][1];
        void *p1 = ft_calloc(count, size);
        void *p2 = calloc(count, size);
        if (p1 == NULL || p2 == NULL) {
            if (p1 != p2) {
                SOFT_ASSERT(0, "calloc NULL mismatch");
            }
        } else {
            /* Compare allocated memory content (should be zero) */
            size_t total = count * size;
            SOFT_ASSERT(memcmp(p1, p2, total) == 0,
                        "ft_calloc memory content mismatch");
            free(p1);
            free(p2);
        }
    }
    /* Test with huge allocation (should return NULL) */
    void *p = ft_calloc(SIZE_MAX, SIZE_MAX);
    SOFT_ASSERT(p == NULL, "ft_calloc should fail for over size_max");
    print_summary();
}
