#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>

int main(){
    printf("\n=====STRTRIM MALLOC FAIL=====\n");

    struct {
        const char *s1;
        const char *set;
        const char *expected;
    } cases[] = {
        /* Basic cases */
        {"", " ", ""},
        {"   ", " ", ""},
        {"hello", " ", "hello"},
        {"  hello  ", " ", "hello"},
        {"\t\nhello\t\n", "\t\n", "hello"},
        {"  hello world  ", " ", "hello world"},
        {"abc", "abc", ""},                    /* all chars in set */
        {"abc", "def", "abc"},                 /* none in set */
        {"abc", "abcd", ""},                   /* all chars in set (includes extra) */
        {"abc", "ad", "bc"},                   /* 'a' trimmed from front, but 'c'? Actually 'c' not in set -> "bc" */
        {"abc", "ac", "b"},                    /* 'a' and 'c' trimmed -> "b" */
        {"abc", "b", "abc"},                   /* 'b' only in middle, not trimmed */
        {"aabbaa", "a", "bb"},                 /* trim leading/trailing 'a' */
        {"aabbaa", "ab", ""},                  /* all chars in set */
        {"  a b c  ", " ", "a b c"},           /* spaces only at ends, middle spaces kept */
        /* Complex sets */
        {"xyz123xyz", "xyz", "123"},
        {"**hello**", "*", "hello"},
        {"*hello*", "*", "hello"},
        {"**hello*", "*", "hello"},
        {"*hello**", "*", "hello"},
        {"*hello* ", "* ", "hello"},           /* set is "* " */
        {" \t\n hello \t\n ", " \t\n", "hello"},
        {"   ", " ", ""},
        {"   ", "", "   "},                    /* empty set -> copy */
        {"", "abc", ""},
        /* Mixed characters not in set */
        {"abca", "b", "abca"},                 /* 'b' not at ends */
        {"abca", "a", "bc"},                   /* trim 'a' at ends */
        {"abca", "abc", ""},                   /* all chars in set */
        {"abca", "bca", ""},                  /* 'a' at ends? Actually set {b,c,a}, all chars in set -> ""? Wait 'abca' contains only a,b,c, all in set, so should be "" */
        {"abca", "bc", "abca"},                /* 'a' not in set, so no trim */
        /* More edge cases: set contains repeated chars (no effect) */
        {"hello", "ll", "hello"},              /* 'l' is in middle, not at ends, so no trim */
        {"llhello", "l", "hello"},             /* trim leading 'l's */
        {"helloll", "l", "hello"},             /* trim trailing 'l's */
        {NULL, NULL, NULL} /* sentinel */
    };

    for (int i = 0; cases[i].s1 != NULL; i++)
    {
        const char *s1 = cases[i].s1;
        const char *set = cases[i].set;

        char *result = ft_strtrim(s1, set);

        /* Ensure result is not NULL (we assume allocation succeeds) */
        SOFT_ASSERT(result == NULL, "ft_strtrim should returned NULL");
		if (result)
			free(result);
    }

	print_summary();
}
