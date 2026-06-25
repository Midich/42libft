#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>

int main(){
    printf("\n=====STRJOIN=====\n");

    struct {
        const char *s1;
        const char *s2;
        const char *expected;
    } cases[] = {
        {"", "", ""},
        {"", "hello", "hello"},
        {"hello", "", "hello"},
        {"hello", "world", "helloworld"},
        {"Hello, ", "World!", "Hello, World!"},
        {"abc", "def", "abcdef"},
        {"123", "456", "123456"},
        {"   ", "   ", "      "},
        {"", " ", " "},
        {" ", "", " "},
        {"abc", "123", "abc123"},
        {"xyz", "XYZ", "xyzXYZ"},
        {"\n", "\t", "\n\t"},
        {NULL, NULL, NULL}
    };

    for (int i = 0; cases[i].s1 != NULL; i++)
    {
        const char *s1 = cases[i].s1;
        const char *s2 = cases[i].s2;
        const char *exp = cases[i].expected;

        char *result = ft_strjoin(s1, s2);

        /* Ensure result is not NULL (we assume allocation succeeds) */
        SOFT_ASSERT(result != NULL, "ft_strjoin returned NULL");

        /* Compare with expected */
        char msg[256];
        snprintf(msg, sizeof(msg), "ft_strjoin('%s', '%s') mismatch", s1, s2);
        SOFT_ASSERT(strcmp(result, exp) == 0, msg);

        /* Ensure the result is a new allocation (not pointing to original strings) */
        SOFT_ASSERT(result != s1 && result != s2,
                    "ft_strjoin returned original pointer (should allocate)");

        /* Check null-termination */
        size_t len = strlen(result);
        SOFT_ASSERT(result[len] == '\0', "ft_strjoin missing null terminator");

        /* Ensure total length matches expected */
        size_t expected_len = strlen(s1) + strlen(s2);
        SOFT_ASSERT(strlen(result) == expected_len,
                    "ft_strjoin length mismatch");

        free(result);
    }

    /* Additional test: s1 and s2 are the same string? Should still work */
    const char *same = "hello";
    char *r = ft_strjoin(same, same);
    SOFT_ASSERT(r != NULL, "ft_strjoin returned NULL");
    SOFT_ASSERT(strcmp(r, "hellohello") == 0,
                "ft_strjoin with same string failed");
    free(r);

    /* Test with very long strings (but limited to avoid excessive time) */
    char long_s1[256], long_s2[256];
    memset(long_s1, 'A', sizeof(long_s1) - 1);
    long_s1[sizeof(long_s1) - 1] = '\0';
    memset(long_s2, 'B', sizeof(long_s2) - 1);
    long_s2[sizeof(long_s2) - 1] = '\0';
    char expected_long[512];
    snprintf(expected_long, sizeof(expected_long), "%s%s", long_s1, long_s2);

    r = ft_strjoin(long_s1, long_s2);
    SOFT_ASSERT(r != NULL, "ft_strjoin returned NULL for long strings");
    SOFT_ASSERT(strcmp(r, expected_long) == 0,
                "ft_strjoin long strings mismatch");
    SOFT_ASSERT(strlen(r) == (strlen(long_s1) + strlen(long_s2)),
                "ft_strjoin long strings length mismatch");
    free(r);
	print_summary();
}
