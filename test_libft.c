#define SOFT_ASSERT(condition, msg) \
    g_total++;\
    if (!condition) \
    { \
        fprintf(stderr, "\e[31mFAIL\e[0m: %s\n", msg); \
        g_failed++;
    }

static size_t g_total = 0;
static size_t g_failed = 0;

//is* functions from ctype test -128-255 EOF and outside char and uchar
//tolower, toupper -128-255 EOF
//atoi 0 1 -1 +1 \t\n\v\f\r  1 max min
//bzero few sizes of buffer
//calloc different sizes + max

