#include "../soft_assert.h"
#include <libft.h>
#include <string.h>

#define MLEN 100
int main()
{
    printf("\n=====STRLEN=====\n");

    char msg[MLEN];

    int i = 0;
    char *test_cases[] = {"", "a", "Hello", "Hello beautiful world", "aaaaa", "jod\0soa\0", "\0", 0};
    while (test_cases[i])
    {
        size_t exp = strlen(test_cases[i]);
        size_t got = ft_strlen(test_cases[i]);
        snprintf(msg, MLEN, "strlen mismatch in test %i, expected=%lu, got=%lu", i, exp, got);
        SOFT_ASSERT(exp==got, msg);
        i++;
    }
    print_summary();
}
