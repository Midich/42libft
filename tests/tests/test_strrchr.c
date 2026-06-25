#include "../soft_assert.h"
#include "libft.h"
#include <string.h>

int main(){
    printf("\n=====STRRCHR=====\n");
    char *s = "hello world";
    /* Search for existing chars */
    char chars[] = {'h', 'e', 'l', 'o', ' ', 'd', 'x', '\0'};
    for (size_t i = 0; i < sizeof(chars)/sizeof(chars[0]); i++) {
        int c = chars[i];
        char *exp = strrchr(s, c);
        char *got = ft_strrchr(s, c);
        SOFT_ASSERT(exp == got, "ft_strrchr mismatch");
		if (got != exp)
			{
				printf("got = %s, exp = %s searched = %c\n", got, exp, c);
				printf("got_ptr = %p, exp_ptr = %p\n", got, exp);
			}
    }
    /* Empty string */
    const char *empty = "";
    SOFT_ASSERT(ft_strrchr(empty, 'a') == NULL, "empty string, char not found");
    SOFT_ASSERT(ft_strrchr(empty, '\0') == (char*)empty, "empty string, null char");
	print_summary();
}
