#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>

int main(){
    printf("\n=====STRTRIM=====\n");

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
        const char *exp = cases[i].expected;

        char *result = ft_strtrim(s1, set);

        /* Ensure result is not NULL (we assume allocation succeeds) */
        SOFT_ASSERT(result != NULL, "ft_strtrim returned NULL");

        /* Compare with expected */
        char msg[256];
        snprintf(msg, sizeof(msg), "ft_strtrim('%s', '%s') mismatch, testno = %d, res = '%s'", s1, set, i, result);
        SOFT_ASSERT(strcmp(result, exp) == 0, msg);

        /* Check that result is a new allocation (not same pointer) */
        SOFT_ASSERT(result != s1, "ft_strtrim returned original pointer (should allocate)");

        free(result);
    }

    /* Additional test: verify that trimming does not remove characters from the middle */
    const char *s = "abcXYZdef";
    const char *set = "abc";
    char *r = ft_strtrim(s, set);
    SOFT_ASSERT(r != NULL, "ft_strtrim returned NULL");
    SOFT_ASSERT(strcmp(r, "XYZdef") == 0, "trim middle preservation failed"); /* 'abc' at start removed, 'def' remains */
    free(r);

    /* Set that includes characters that appear only in middle, should not affect */
    s = "hello world";
    set = "l";
    r = ft_strtrim(s, set);
    SOFT_ASSERT(r != NULL, "ft_strtrim returned NULL");
    SOFT_ASSERT(strcmp(r, "hello world") == 0, "middle char in set should not be trimmed");
    free(r);

    /* Test with set containing characters not in string */
    s = "hello";
    set = "xyz";
    r = ft_strtrim(s, set);
    SOFT_ASSERT(r != NULL, "ft_strtrim returned NULL");
    SOFT_ASSERT(strcmp(r, "hello") == 0, "set not present should return copy");
    free(r);
	print_summary();
}
