#include "libft.h"
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define MESSAGE_LEN 100
#define SOFT_ASSERT(condition, msg) \
do { \
    g_total++;\
    if (!(condition)) \
    { \
        fprintf(stderr, "\e[31mFAIL\e[0m: %s\n", msg); \
        g_failed++; \
    } \
} while(0);

static size_t g_total = 0;
static size_t g_failed = 0;
static char smsg[MESSAGE_LEN];

//is* functions from ctype test -128-255 EOF and outside char and uchar
//tolower, toupper -128-255 EOF
//atoi 0 1 -1 +1 \t\n\v\f\r  1 max min
//bzero few sizes of buffer
//calloc different sizes + max
static void print_summary()
{
	printf("\n=====SUMMARY=====\n");
	printf("Total: %lu\n", g_total);
	printf("Passed: %lu\n", g_total - g_failed);
	printf("Failed: %lu\n", g_failed);
	if (!g_failed)
		printf("\e[32mAll test passed\e[0m\n");
	else
		printf("\e[31Some test failed\e[0m\n");
	
}

static void test_ctype_func()
{
	printf("\n=====CTYPE FUNCTIONS=====\n");

	int expected;
	int got;
	
	for (int c = -128; c <= 255; c++)
	{
		expected = isalpha(c)? 1 : 0;
		got = ft_isalpha(c);
		snprintf(smsg, MESSAGE_LEN, "isalpha mismatch for c=%i, expected=%i, got=%i", c, expected, got);
		SOFT_ASSERT(expected == got, smsg);

		expected = isdigit(c)? 1 : 0;
		got = ft_isdigit(c);
		snprintf(smsg, MESSAGE_LEN, "isdigit mismatch for c=%i, expected=%i, got=%i", c, expected, got);
		SOFT_ASSERT(expected == got, smsg);

		expected = isalnum(c)? 1 : 0;
		got = ft_isalnum(c);
		snprintf(smsg, MESSAGE_LEN, "isalnum mismatch for c=%i, expected=%i, got=%i", c, expected, got);
		SOFT_ASSERT(expected == got, smsg);

		expected = isascii(c)? 1 : 0;
		got = ft_isascii(c);
		snprintf(smsg, MESSAGE_LEN, "isascii mismatch for c=%i, expected=%i, got=%i", c, expected, got);
		SOFT_ASSERT(expected == got, smsg);

		expected = isprint(c)? 1 : 0;
		got = ft_isprint(c);
		snprintf(smsg, MESSAGE_LEN, "isprint mismatch for c=%i, expected=%i, got=%i", c, expected, got);
		SOFT_ASSERT(expected == got, smsg);
	}

	int tc[] = {300, -300, EOF};
	for (size_t i = 0; i < sizeof(tc) / sizeof(tc[0]); i++)
	{
		int c = tc[i];
		
		expected = isalpha(c)? 1 : 0;
		got = ft_isalpha(c);
		snprintf(smsg, MESSAGE_LEN, "isalpha mismatch for c=%i, expected=%i, got=%i", c, expected, got);
		SOFT_ASSERT(expected == got, smsg);

		expected = isdigit(c)? 1 : 0;
		got = ft_isdigit(c);
		snprintf(smsg, MESSAGE_LEN, "isdigit mismatch for c=%i, expected=%i, got=%i", c, expected, got);
		SOFT_ASSERT(expected == got, smsg);

		expected = isalnum(c)? 1 : 0;
		got = ft_isalnum(c);
		snprintf(smsg, MESSAGE_LEN, "isalnum mismatch for c=%i, expected=%i, got=%i", c, expected, got);
		SOFT_ASSERT(expected == got, smsg);

		expected = isascii(c)? 1 : 0;
		got = ft_isascii(c);
		snprintf(smsg, MESSAGE_LEN, "isascii mismatch for c=%i, expected=%i, got=%i", c, expected, got);
		SOFT_ASSERT(expected == got, smsg);

		expected = isprint(c)? 1 : 0;
		got = ft_isprint(c);
		snprintf(smsg, MESSAGE_LEN, "isprint mismatch for c=%i, expected=%i, got=%i", c, expected, got);
		SOFT_ASSERT(expected == got, smsg);
	}
}

static void test_tolowertoupper()
{
	printf("\n=====TOLOWER\\TOUPPER FUNCTIONS=====\n");

	int expected;
	int got;
	
	for (int c = -128; c <= 255; c++)
	{
		expected = tolower(c);
		got = ft_tolower(c);
		snprintf(smsg, MESSAGE_LEN, "tolower mismatch for c=%i, expected=%i, got=%i", c, expected, got);
		SOFT_ASSERT(expected == got, smsg);

		expected = toupper(c);
		got = ft_toupper(c);
		snprintf(smsg, MESSAGE_LEN, "toupper mismatch for c=%i, expected=%i, got=%i", c, expected, got);
		SOFT_ASSERT(expected == got, smsg);
	}
}

static void test_strlen()
{
	printf("\n=====STRLEN=====\n");

	int i = 0;
	char *test_cases[] = {"", "a", "Hello", "Hello beautiful world", "aaaaa", "jod\0soa\0", "\0", 0};
	while (test_cases[i])
	{
		size_t exp = strlen(test_cases[i]);
		size_t got = ft_strlen(test_cases[i]);
		snprintf(smsg, MESSAGE_LEN, "strlen mismatch in test %i, expected=%lu, got=%lu", i, exp, got);
		SOFT_ASSERT(exp==got, smsg);
		i++;
	}
}

static void test_memset()
{
	printf("\n=====MEMSET=====\n");
	unsigned char buff1[256], buff2[256];
	int vals[] = {0, 1, 10, 255, 256, -1};
	int  
}

int main(void)
{
	test_ctype_func();
	test_tolowertoupper();
	test_strlen();
	print_summary();
}
