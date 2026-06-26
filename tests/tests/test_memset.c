#include "../soft_assert.h"
#include <libft.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#define MLEN 100
int main()
{
    printf("\n=====MEMSET=====\n");

    char msg[MLEN];
    unsigned char buff1[256], buff2[256];
    int sizes[] = {0, 1, 10, 100, 200, 255, 256};
    int values[] = { 0, 1, 10, 100, 255, 256, -1, 170, 58, 1243};

    for (size_t i = 0; i < sizeof(sizes)/sizeof(sizes[0]); i++)
    {
        int s = sizes[i];
        for (size_t j = 0; j < sizeof(values)/sizeof(values[0]); j++)
        {
    		bzero(buff1, 256);
    		bzero(buff2, 256);
            int v = values[j];
            memset(buff1, v, s);
            void *r = ft_memset(buff2, v, s);
            SOFT_ASSERT(r == buff2, "Return mismatch");
            snprintf(msg, MLEN, "Buffers mismatch for size=%i, value=%i\n", s, v);
            SOFT_ASSERT(!memcmp(buff1, buff2, sizeof(buff1)), msg);

        }
    }
    print_summary();
}
