#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>

int main(){
    printf("\n=====SUBSTR=====\n");

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
        const char *exp = cases[i].expected;

        /* Compute expected if not provided */
        char *expected = NULL;

            expected = strdup(exp);  /* strdup for consistency, will free later */

        if (!expected)
        {
            SOFT_ASSERT(0, "Failed to allocate expected string");
            continue;
        }

        char *result = ft_substr(s, start, len);

        /* Ensure result is not NULL (allocation should succeed) */
        SOFT_ASSERT(result != NULL, "ft_substr returned NULL");

        /* Compare */
        char msg[256];
        snprintf(msg, sizeof(msg), "ft_substr('%s', %u, %zu) mismatch", s, start, len);
        SOFT_ASSERT(strcmp(result, expected) == 0, msg);

        /* Ensure result is a new allocation */
        SOFT_ASSERT(result != s, "ft_substr returned original pointer");

        /* Check null-termination */
        size_t result_len = strlen(result);
        SOFT_ASSERT(result[result_len] == '\0', "ft_substr missing null terminator");

        /* Free */
        free(result);
        free(expected);
    }
	print_summary();
}
