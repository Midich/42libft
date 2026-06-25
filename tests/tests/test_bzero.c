#include "../soft_assert.h"
#include <libft.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#define MLEN 100
int main()
{
    printf("\n=====BZERO=====\n");

    char msg[MLEN];
    char buff1[256], buff2[256];
    int sizes[] = {0, 1, 10, 100, 200, 255, 256};

    for (size_t i = 0; i < sizeof(sizes)/sizeof(sizes[0]); i++)
    {
        int s = sizes[i];
        {
    		memset(buff1, 'A', sizeof(buff1));
    		memset(buff2, 'A', sizeof(buff2));
            bzero(buff1, sizeof(buff1));
            ft_bzero(buff2, sizeof(buff2));
            snprintf(msg, MLEN, "Buffers mismatch for size=%i\n", s);
            SOFT_ASSERT(!memcmp(buff1, buff2, sizeof(buff1)), msg);

        }
    }
    print_summary();
}
