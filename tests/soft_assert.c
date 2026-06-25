#include "soft_assert.h"

size_t g_total = 0;
size_t g_failed = 0;

void print_summary()
{
    printf("\n=====SUMMARY=====\n");
    printf("Total: %lu\n", g_total);
    printf("Passed: %lu\n", g_total - g_failed);
    printf("Failed: %lu\n", g_failed);
    if (!g_failed)
        printf("\e[32mAll test passed\e[0m\n");
    else
        printf("\e[31mSome test failed\e[0m\n");

}
