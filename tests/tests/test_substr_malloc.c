#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>

#define oldmalloc(size_t)

int main(){
    printf("\n=====SUBSTR_MALLOC_FAIL=====\n");

    struct {
        const char *s;
        unsigned int start;
        size_t len;
        const char *expected;
    } cases[] = {
        {"hello", 0, 0, ""},
        {"hello", 0, 1, "h"},
        {"hello", 0, 5, "hello"},
        {"hello", 0, 10, "hello"},
        {"hello", 1, 3, "ell"},
        {"hello", 1, 0, ""},
        {"hello", 5, 0, ""},
        {"hello", 5, 5, ""},          /* start == len -> empty */
        {"hello", 6, 0, ""},          /* start > len -> empty */
        {"hello", 6, 5, ""},
        {"", 0, 0, ""},
        {"", 0, 5, ""},
        {"abcdef", 2, 4, "cdef"},
        {"abcdef", 2, 10, "cdef"},
        {"abcdef", 6, 0, ""},
        {"abcdef", 6, 5, ""},
        {"12345", 0, 3, "123"},
        {"12345", 3, 2, "45"},
        {"12345", 3, 0, ""},
        {"   ", 0, 3, "   "},
        {"   ", 1, 1, " "},
        {"   ", 3, 1, ""},
        {NULL, 0, 0, NULL} /* sentinel */
    };

    for (int i = 0; cases[i].s != NULL; i++)
    {
        const char *s = cases[i].s;
        unsigned int start = cases[i].start;
        size_t len = cases[i].len;

        /* Compute expected if not provided */

        char *result = ft_substr(s, start, len);

        /* Ensure result is not NULL (allocation should succeed) */
        SOFT_ASSERT(result == NULL, "ft_substr should returned NULL");
		if(result)
			free(result);
    }
	print_summary();
}
