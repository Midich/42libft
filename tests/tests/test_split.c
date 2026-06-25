#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>

int main(){
    printf("\n=====SPLIT======\n");

    struct {
        const char *s;
        char c;
        const char **expected;
    } cases[] = {
        {"", ' ', (const char *[]){NULL}},
        {"   ", ' ', (const char *[]){NULL}},
        {"hello", ' ', (const char *[]){ "hello", NULL }},
        {" hello ", ' ', (const char *[]){ "hello", NULL }},
        {"  hello  world  ", ' ', (const char *[]){ "hello", "world", NULL }},
        {"a  b  c", ' ', (const char *[]){ "a", "b", "c", NULL }},
        {"a:b:c", ':', (const char *[]){ "a", "b", "c", NULL }},
        {"a::b", ':', (const char *[]){ "a", "b", NULL }},
        {":a:b:", ':', (const char *[]){ "a", "b", NULL }},
        {"abc", 'x', (const char *[]){ "abc", NULL }},
        {"xabcx", 'x', (const char *[]){ "abc", NULL }},
        {"xxx", 'x', (const char *[]){NULL}},
        {"a", ' ', (const char *[]){ "a", NULL }},
        {"a b c d e", ' ', (const char *[]){ "a", "b", "c", "d", "e", NULL }},
        {NULL, 0, NULL}
    };

    for (int i = 0; cases[i].s != NULL; i++)
    {
        const char *s = cases[i].s;
        char c = cases[i].c;
        const char **exp = cases[i].expected;

        char **result = ft_split(s, c);

        /* 1. Check that result is not NULL (we don't test allocation failure) */
        SOFT_ASSERT(result != NULL, "ft_split returned NULL");

        /* 2. Count number of strings in result */
        int count = 0;
        while (result[count] != NULL)
            count++;

        /* 3. Count expected strings */
        int exp_count = 0;
        while (exp[exp_count] != NULL)
            exp_count++;

        /* 4. Compare count */
        char msg[256];
        snprintf(msg, sizeof(msg), "split count mismatch for '%s' (delimiter '%c')", s, c);
        SOFT_ASSERT(count == exp_count, msg);

        /* 5. Compare each string */
        for (int j = 0; j < count; j++)
        {
            snprintf(msg, sizeof(msg), "string %d mismatch for '%s', result: '%s'", j, s, result[j]);
            SOFT_ASSERT(strcmp(result[j], exp[j]) == 0, msg);
        }

        /* 6. Free allocated memory */
        for (int j = 0; j < count; j++)
            free(result[j]);
        free(result);
    }
	print_summary();
}
