#include "../soft_assert.h"
#include "libft.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("\n=====CALLOC MALLOC FAIl=====\n");
    /* Test with various count, size combinations */
    size_t tests[][2] = {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}, {5, 10}, {10, 5}, {100, 1}
    };
    for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        size_t count = tests[i][0];
        size_t size = tests[i][1];
        void *p1 = ft_calloc(count, size);
        SOFT_ASSERT(p1==NULL, "calloc should returned NULL");
		if (p1)
			free(p1);
    }
    print_summary();
}
