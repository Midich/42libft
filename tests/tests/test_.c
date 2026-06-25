#include "../soft_assert.h"
#include <libft.h>

#define MLEN 100
int main()
{
    printf("\n=====TEST=====\n");

    char msg[MLEN];
    int expected;
    int got;

    for (int c = -128; c <= 255; c++)
    {
        expected = test(c);
        got = ft_test(c);
        snprintf(msg, MLEN, "test mismatch for c=%i, expected=%i, got=%i", c, expected, got);
        SOFT_ASSERT(expected == got, msg);

        expected = test(c);
        got = ft_test(c);
        snprintf(msg, MLEN, "test mismatch for c=%i, expected=%i, got=%i", c, expected, got);
        SOFT_ASSERT(expected == got, msg);
    }
    print_summary();
}
