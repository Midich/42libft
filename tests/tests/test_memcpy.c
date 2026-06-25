#include "../soft_assert.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main() {
    printf("\n=====MEMCPY=====\n");
    unsigned char src[128], dst1[128], dst2[128];
    for (int i = 0; i < 128; i++) src[i] = i;
    /* Copy various lengths */
    size_t lens[] = {0, 1, 5, 10, 64, 128};
    for (size_t li = 0; li < sizeof(lens)/sizeof(lens[0]); li++) {
        size_t n = lens[li];
        memset(dst1, 0xAA, sizeof(dst1));
        memset(dst2, 0xAA, sizeof(dst2));
        void *r1 = ft_memcpy(dst1, src, n);
        memcpy(dst2, src, n);
        SOFT_ASSERT(r1 == dst1, "memcpy return value mismatch");
        SOFT_ASSERT(memcmp(dst1, dst2, sizeof(dst1)) == 0,
                    "memcpy content mismatch");
    }
	print_summary();
}
