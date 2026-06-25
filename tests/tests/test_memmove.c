#include "../soft_assert.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
int main() {
    printf("\n=====MEMMOVE=====\n");
    unsigned char buf1[128], buf2[128];
    /* Fill both with same pattern */
    for (int i = 0; i < 128; i++) buf1[i] = buf2[i] = i;
    /* Overlap: move forward (src before dst) */
    size_t src_start = 10, dst_start = 20, len = 30;
    void *r1 = ft_memmove(buf1 + dst_start, buf1 + src_start, len);
    void *r2 = memmove(buf2 + dst_start, buf2 + src_start, len);
    SOFT_ASSERT(r1 == (buf1 + dst_start) && r2 == (buf2 + dst_start),
                "memmove return forward");
    SOFT_ASSERT(memcmp(buf1, buf2, 128) == 0, "memmove forward content");

    /* Overlap: move backward (src after dst) */
    src_start = 30; dst_start = 10; len = 25;
    r1 = ft_memmove(buf1 + dst_start, buf1 + src_start, len);
    r2 = memmove(buf2 + dst_start, buf2 + src_start, len);
    SOFT_ASSERT(memcmp(buf1, buf2, 128) == 0, "memmove backward content");

    /* No overlap */
    src_start = 0; dst_start = 50; len = 40;
    r1 = ft_memmove(buf1 + dst_start, buf1 + src_start, len);
    r2 = memmove(buf2 + dst_start, buf2 + src_start, len);
    SOFT_ASSERT(memcmp(buf1, buf2, 128) == 0, "memmove non-overlap");

    /* Zero length */
    ft_memmove(buf1, buf1 + 10, 0);
    memmove(buf2, buf2 + 10, 0);
    SOFT_ASSERT(memcmp(buf1, buf2, 128) == 0, "memmove zero length");
    print_summary();
    
}
