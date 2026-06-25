#include "../soft_assert.h"
#include "libft.h"
#include <string.h>

int main(){
    printf("\n=====STRNCMP=====\n");
    struct {
        const char *s1;
        const char *s2;
        size_t n;
    } cases[] = {
        {"", "", 0},
        {"a", "a", 1},
        {"abc", "abc", 5},
        {"abc", "abd", 3},
        {"abc", "abcd", 4},
        {"abc", "abc", 2},
        {"abc", "abd", 1},
        {"abc", "abc", 0},
        {"", "a", 1},
        {"a", "", 1}
    };
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        int exp = strncmp(cases[i].s1, cases[i].s2, cases[i].n);
        int got = ft_strncmp(cases[i].s1, cases[i].s2, cases[i].n);
        char msg[200];
        snprintf(msg, 200, "ft_strncmp mismatch for s1=%s, s2=%s, n=%lu. EXP: %i, GOT: %i", cases[i].s1, cases[i].s2, cases[i].n, exp, got);
        SOFT_ASSERT(exp == got, msg);
    }
    /* Additional edge cases */
    SOFT_ASSERT(ft_strncmp("", "a", 1) < 0, "empty vs a");
    SOFT_ASSERT(ft_strncmp("a", "", 1) > 0, "a vs empty");
    SOFT_ASSERT(ft_strncmp("", "", 0) == 0, "both empty");
    SOFT_ASSERT(ft_strncmp("abc", "def", 0) == 0, "n=0");
	print_summary();
}
