#include "../soft_assert.h"
#include "libft.h"
#include <bsd/string.h>


int main(){
    printf("\n=====STRNSTR=====\n");
    struct {
        const char *haystack;
        const char *needle;
        size_t len;
        const char *expected;  /* expected pointer or NULL */
    } cases[] = {
        {"hello world", "world", 11, "world"},
        {"hello world", "world", 5, NULL},
        {"hello world", "", 11, "hello world"},  /* empty needle returns haystack */
        {"", "hello", 0, NULL},
        {"abc", "abc", 3, "abc"},
        {"abc", "abc", 2, NULL},
        {"abc", "b", 3, "bc"},
        {"abc", "b", 1, NULL},
        {"abc", "d", 3, NULL},
        {"aaa", "aa", 3, "aaa"},
        {"aaab", "aa", 4, "aaab"},
        {"aaab", "aa", 2, NULL},
    };
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        const char *hay = cases[i].haystack;
        const char *nee = cases[i].needle;
        size_t len = cases[i].len;
        char *exp = strnstr(hay, nee, len);
        char *got = ft_strnstr(hay, nee, len);
        /* Check pointer equality; if both NULL or point to same char */
        if (exp == NULL) {
            SOFT_ASSERT(got == NULL, "ft_strnstr should return NULL");
			if (got != exp)
			{
				printf("got = %s, exp = %s len = %d\n", got, exp, (int)len);
				printf("hay = %s, need = %s\n", hay, nee);
			}
        } else {
            SOFT_ASSERT(got == exp, "ft_strnstr pointer mismatch");
			if (got != exp)
			{
				printf("got = %s, exp = %s len = %d\n", got, exp, (int)len);
				printf("got_ptr = %p, exp_ptr = %p\n", got, exp);
				printf("hay = %s, need = %s\n", hay, nee);
			}
        }
    }
	print_summary();
}
