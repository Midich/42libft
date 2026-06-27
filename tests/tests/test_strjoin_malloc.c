#include "../soft_assert.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>

int main(){
    printf("\n=====STRJOIN MALLOC FAIL=====\n");

    struct {
        const char *s1;
        const char *s2;
        const char *expected;
    } cases[] = {
        {"", "", ""},
        {"", "hello", "hello"},
        {"hello", "", "hello"},
        {"hello", "world", "helloworld"},
        {"Hello, ", "World!", "Hello, World!"},
        {"abc", "def", "abcdef"},
        {"123", "456", "123456"},
        {"   ", "   ", "      "},
        {"", " ", " "},
        {" ", "", " "},
        {"abc", "123", "abc123"},
        {"xyz", "XYZ", "xyzXYZ"},
        {"\n", "\t", "\n\t"},
        {NULL, NULL, NULL}
    };

    for (int i = 0; cases[i].s1 != NULL; i++)
    {
        const char *s1 = cases[i].s1;
        const char *s2 = cases[i].s2;

        char *result = ft_strjoin(s1, s2);

        /* Ensure result is not NULL (we assume allocation succeeds) */
        SOFT_ASSERT(result == NULL, "ft_strjoin should returned NULL");
		if (result)
		{
			free(result);
		}
    }

	print_summary();
}
