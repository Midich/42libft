#include "../soft_assert.h"
#include <libft.h>
#include <ctype.h>

#define MLEN 100
int main()
{
    printf("\n=====CTYPE FUNCTIONS=====\n");

    char msg[MLEN];
    int expected;
    int got;

    for (int c = -128; c <= 255; c++)
    {
        expected = isalpha(c)? 1 : 0;
        got = ft_isalpha(c);
        snprintf(msg, MLEN, "isalpha mismatch for c=%i, expected=%i, got=%i", c, expected, got);
        SOFT_ASSERT(expected == got, msg);

        expected = isdigit(c)? 1 : 0;
        got = ft_isdigit(c);
        snprintf(msg, MLEN, "isdigit mismatch for c=%i, expected=%i, got=%i", c, expected, got);
        SOFT_ASSERT(expected == got, msg);

        expected = isalnum(c)? 1 : 0;
        got = ft_isalnum(c);
        snprintf(msg, MLEN, "isalnum mismatch for c=%i, expected=%i, got=%i", c, expected, got);
        SOFT_ASSERT(expected == got, msg);

        expected = isascii(c)? 1 : 0;
        got = ft_isascii(c);
        snprintf(msg, MLEN, "isascii mismatch for c=%i, expected=%i, got=%i", c, expected, got);
        SOFT_ASSERT(expected == got, msg);

        expected = isprint(c)? 1 : 0;
        got = ft_isprint(c);
        snprintf(msg, MLEN, "isprint mismatch for c=%i, expected=%i, got=%i", c, expected, got);
        SOFT_ASSERT(expected == got, msg);
    }

    int tc[] = {300, -300, EOF};
    for (size_t i = 0; i < sizeof(tc) / sizeof(tc[0]); i++)
    {
        int c = tc[i];

        expected = isalpha(c)? 1 : 0;
        got = ft_isalpha(c);
        snprintf(msg, MLEN, "isalpha mismatch for c=%i, expected=%i, got=%i", c, expected, got);
        SOFT_ASSERT(expected == got, msg);

        expected = isdigit(c)? 1 : 0;
        got = ft_isdigit(c);
        snprintf(msg, MLEN, "isdigit mismatch for c=%i, expected=%i, got=%i", c, expected, got);
        SOFT_ASSERT(expected == got, msg);

        expected = isalnum(c)? 1 : 0;
        got = ft_isalnum(c);
        snprintf(msg, MLEN, "isalnum mismatch for c=%i, expected=%i, got=%i", c, expected, got);
        SOFT_ASSERT(expected == got, msg);

        expected = isascii(c)? 1 : 0;
        got = ft_isascii(c);
        snprintf(msg, MLEN, "isascii mismatch for c=%i, expected=%i, got=%i", c, expected, got);
        SOFT_ASSERT(expected == got, msg);

        expected = isprint(c)? 1 : 0;
        got = ft_isprint(c);
        snprintf(msg, MLEN, "isprint mismatch for c=%i, expected=%i, got=%i", c, expected, got);
        SOFT_ASSERT(expected == got, msg);
    }
    print_summary();
}
