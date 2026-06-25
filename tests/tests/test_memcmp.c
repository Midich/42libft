#include "../soft_assert.h"
#include "libft.h"
#include <string.h>

int main(){
    printf("\n=====MEMCMP=====\n");
    unsigned char a[64], b[64];
    for (int i = 0; i < 64; i++) { a[i] = i; b[i] = i; }
    /* Equal blocks */
    SOFT_ASSERT(ft_memcmp(a, b, 64) == 0, "memcmp equal");
    /* Different at position */
    b[10] = 200;
    int exp = memcmp(a, b, 64);
    int got = ft_memcmp(a, b, 64);
    SOFT_ASSERT((exp > 0 && got > 0) || (exp < 0 && got < 0) || (exp == 0 && got == 0),
                "memcmp sign mismatch");
    /* Zero length */
    SOFT_ASSERT(ft_memcmp(a, b, 0) == 0, "memcmp zero length");
    /* Compare with n less than difference */
    SOFT_ASSERT(ft_memcmp(a, b, 10) == 0, "memcmp with n before difference");
    /* Edge: compare with NULL? Not defined */
	print_summary();
}
