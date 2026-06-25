#include "../soft_assert.h"
#include "libft.h"
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>


static char identity(unsigned int i, char c)
{
    (void)i;
    return (c);
}

static char to_upper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

static char add_index(unsigned int i, char c)
{
    return (c + i);
}

static char transform(unsigned int i, char c)
{
    if (i % 2 == 0)
        return (c);
    else
        return (c + 1);
}

int main()
{
    printf("\n=====STRMAPI=====\n");

    struct {
        const char *s;
        char (*f)(unsigned int, char);
        const char *expected;
    } cases[] = {
        {"", identity, ""},
        {"hello", identity, "hello"},
        {"hello", to_upper, "HELLO"},
        {"abc", add_index, "ace"},
        {"abc", transform, "acc"},
        {"xyz", add_index, "xz|"},
        {NULL, NULL, NULL}
    };

    for (int i = 0; cases[i].s != NULL; i++)
    {
        const char *s = cases[i].s;
        char (*f)(unsigned int, char) = cases[i].f;
        const char *exp = cases[i].expected;

        char *result = ft_strmapi(s, f);

        /* Ensure result is not NULL */
        SOFT_ASSERT(result != NULL, "ft_strmapi returned NULL");

        /* Compare with expected */
        char msg[256];
        snprintf(msg, sizeof(msg), "ft_strmapi mismatch for '%s'", s);
        SOFT_ASSERT(strcmp(result, exp) == 0, msg);

        /* Check null-termination */
        size_t len = strlen(result);
        SOFT_ASSERT(result[len] == '\0', "ft_strmapi missing null terminator");

        /* Verify that f was called with the correct indices by checking if
           the result matches a manual application */
        char manual[256];
        size_t j = 0;
        while (s[j])
        {
            manual[j] = f(j, s[j]);
            j++;
        }
        manual[j] = '\0';
        SOFT_ASSERT(strcmp(result, manual) == 0, "ft_strmapi result differs from manual application");

        free(result);
    }

    /* Additional edge case: string with special characters (non-ASCII) */
    const char *special = "café";
    char *result = ft_strmapi(special, identity);
    SOFT_ASSERT(result != NULL, "ft_strmapi returned NULL on special chars");
    SOFT_ASSERT(strcmp(result, special) == 0, "ft_strmapi identity on special chars");
    free(result);
	print_summary();
}
