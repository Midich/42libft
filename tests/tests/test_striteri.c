#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>

static void to_upper_at_index(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

static void add_index_to_char(unsigned int i, char *c)
{
    *c = *c + i;
}

static void alternate_case(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = *c + 1;   /* shift every even index char */
    else
        *c = *c - 1;   /* shift every odd index char */
}

int main()
{
    printf("\n=====STRITERI=====\n");

    struct {
        char *s;
        void (*f)(unsigned int, char *);
        const char *expected;
    } cases[] = {
        {(char *)"", to_upper_at_index, ""},
        {(char *)"hello", to_upper_at_index, "HELLO"},
        {(char *)"abc", add_index_to_char, "ace"},
        {(char *)"abc", alternate_case, "bad"},
        {NULL, NULL, NULL} /* sentinel */
    };

    for (int i = 0; cases[i].s != NULL; i++)
    {
        char *copy = strdup(cases[i].s);
        if (!copy)
        {
            SOFT_ASSERT(0, "strdup failed in test");
            continue;
        }

        /* Apply ft_striteri */
        ft_striteri(copy, cases[i].f);

        /* Check result */
        char msg[256];
        snprintf(msg, sizeof(msg), "ft_striteri mismatch for '%s'", cases[i].s);
        SOFT_ASSERT(strcmp(copy, cases[i].expected) == 0, msg);

        free(copy);
    }
	print_summary();
}
