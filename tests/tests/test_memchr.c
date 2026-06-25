#include "../soft_assert.h"
#include "libft.h"
#include <string.h>

int main(){
    printf("\n=====MEMCHR=====\n");
    unsigned char buf[64];
    for (int i = 0; i < 64; i++) buf[i] = i;
    /* Search various chars and lengths */
    size_t lens[] = {0, 1, 5, 10, 32, 64};
    int chars[] = {0, 1, 10, 63, 64, 255, -1, 200};
    for (size_t li = 0; li < sizeof(lens)/sizeof(lens[0]); li++) {
        size_t n = lens[li];
        for (size_t ci = 0; ci < sizeof(chars)/sizeof(chars[0]); ci++) {
            int c = chars[ci];
            void *exp = memchr(buf, c, n);
            void *got = ft_memchr(buf, c, n);
            SOFT_ASSERT(exp == got, "ft_memchr mismatch");
        }
    }
    print_summary();
}
