#ifndef SOFT_ASSERT_H
# define SOFT_ASSERT_H
# include <stddef.h>
# include <stdio.h>

extern size_t g_total;
extern size_t g_failed;

# define SOFT_ASSERT(condition, msg) \
do { \
    g_total++;\
    if (!(condition)) \
    { \
        fprintf(stderr, "\e[31mFAIL\e[0m: %s\n", msg); \
        g_failed++; \
    } \
} while(0);

void print_summary();

#endif
