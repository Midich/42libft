#include "../soft_assert.h"
#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>
int main(){
    printf("\n=====STRLCPY=====\n");
    char dst1[64], dst2[64];
    const char *srcs[] = {"", "hello", "long string that will be truncated"};
    size_t sizes[] = {0, 1, 5, 10, 64};

    for (size_t si = 0; si < sizeof(srcs)/sizeof(srcs[0]); si++) {
        const char *src = srcs[si];
        size_t src_len = strlen(src);
        for (size_t di = 0; di < sizeof(sizes)/sizeof(sizes[0]); di++) {
            size_t size = sizes[di];

            /* Fill both with known pattern */
            memset(dst1, 0x00, sizeof(dst1));
            memset(dst2, 0x00, sizeof(dst2));
            size_t ret1 = ft_strlcpy(dst1, src, size);

            size_t ret2 = strlcpy(dst2, src, size);
            SOFT_ASSERT(ret1 == src_len, "ft_strlcpy return value");
            SOFT_ASSERT(ret1 == ret2, "return value mismatch with reference");
            if (size > 0) {
                SOFT_ASSERT(dst1[size-1] == '\0', "null‑termination");
                size_t cmp_len = (size - 1 < src_len) ? size - 1 : src_len;
                SOFT_ASSERT(memcmp(dst1, dst2, cmp_len) == 0,
                            "content mismatch");
            }
        }
    }
    print_summary();
}
