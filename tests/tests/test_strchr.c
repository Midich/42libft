#include "../soft_assert.h"
#include "libft.h"
#include <string.h>

int main(){
    printf("\n=====STRCHR=====\n");
    const char *s1 = "hello world";
    /* Existing characters */
    char chars[] = {'h', 'e', 'l', 'o', ' ', 'w', 'r', 'd'};
    for (size_t i = 0; i < sizeof(chars)/sizeof(chars[0]); i++) {
        int c = chars[i];
        SOFT_ASSERT(ft_strchr(s1, c) == strchr(s1, c), "strchr existing");
    }
    /* Null terminator */
    SOFT_ASSERT(ft_strchr(s1, '\0') == strchr(s1, '\0'), "strchr null terminator");
    /* Not found */
    SOFT_ASSERT(ft_strchr(s1, 'x') == NULL, "strchr not found");
    /* Empty string */
    const char *empty = "";
    SOFT_ASSERT(ft_strchr(empty, 'a') == NULL, "strchr empty not found");
    SOFT_ASSERT(ft_strchr(empty, '\0') == (char*)empty, "strchr empty null");

    /* Values > 255 and negative – cast to unsigned char */
    SOFT_ASSERT(ft_strchr(s1, 256) == strchr(s1, 256), "strchr c=256 (== '\\0')");
    SOFT_ASSERT(ft_strchr(s1, -1) == strchr(s1, -1), "strchr c=-1 (== 255)");

    /* String containing byte 255 */
    unsigned char s2[10] = "abc";
    s2[3] = 255;
    s2[4] = '\0';
    SOFT_ASSERT(ft_strchr((char*)s2, 255) == strchr((char*)s2, 255),
                "strchr char 255");
    SOFT_ASSERT(ft_strchr((char*)s2, -1) == strchr((char*)s2, -1),
                "strchr c=-1 with 255");
	print_summary();
}

