#include "../soft_assert.h"
#include "libft.h"
#include <string.h>

int main(){
    printf("\n=====STRLCAT=====\n");
    char dst1[64], dst2[64];
    const char *src = "world";
    size_t sizes[] = {0, 1, 5, 10, 64};
    const char *init[] = {"", "hello", "hi"};
    for (size_t ii = 0; ii < sizeof(init)/sizeof(init[0]); ii++) {
        const char *init_s = init[ii];
        size_t init_len = strlen(init_s);
        for (size_t si = 0; si < sizeof(sizes)/sizeof(sizes[0]); si++) {
            size_t size = sizes[si];

            strcpy(dst1, init_s);
            strcpy(dst2, init_s);
            size_t ret1 = ft_strlcat(dst1, src, size);
			size_t ret2 = strlcat(dst2, src, size);
            SOFT_ASSERT(ret1 == ret2, "ft_strlcat return value");
			SOFT_ASSERT(memcmp(dst1, dst2, strlen(dst2) + 1) == 0,
                            "ft_strlcat vs strlcat content");
            /* Check destination content */
            if (size > init_len) {
                /* Should have appended some chars */
                size_t app_len = size - init_len - 1;
                if (app_len > strlen(src)) app_len = strlen(src);
                /* Check that dst1 ends with src prefix */
                char *pos = dst1 + init_len;
                SOFT_ASSERT(memcmp(pos, src, app_len) == 0,
                            "ft_strlcat append content");
                SOFT_ASSERT(dst1[init_len + app_len] == '\0',
                            "ft_strlcat null-termination");
            } else {
                /* size <= init_len: nothing appended, dst unchanged */
                SOFT_ASSERT(strcmp(dst1, init_s) == 0,
                            "ft_strlcat should not modify when size <= init_len");
            }
        }
    }
    print_summary();
}
