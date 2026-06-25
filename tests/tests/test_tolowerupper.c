#include "../soft_assert.h"
#include <libft.h>
#include <ctype.h>

#define MLEN 100
int main()
{
    printf("\n=====TOLOWER\\TOUPPER FUNCTIONS=====\n");

    char msg[MLEN];
    int expected;
    int got;

    for (int c = -128; c <= 255; c++)
    {
        expected = tolower(c);
        got = ft_tolower(c);
        snprintf(msg, MLEN, "tolower mismatch for c=%i, expected=%i, got=%i", c, expected, got);
        SOFT_ASSERT(expected == got, msg);

        expected = toupper(c);
        got = ft_toupper(c);
        snprintf(msg, MLEN, "toupper mismatch for c=%i, expected=%i, got=%i", c, expected, got);
        SOFT_ASSERT(expected == got, msg);
    }
    print_summary();
}
