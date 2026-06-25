#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>

static int sign(int x)
{
	return ((x > 0) - (x < 0));
}

int main()
{
	printf("ft_strncmp\t");

	/* 1 */ check(ft_strncmp("t", "", 0) == 0);
	/* 2 */ check(ft_strncmp("1234", "1235", 3) == 0);
	/* 3 */ check(ft_strncmp("1234", "1235", 4) < 0);
	/* 4 */ check(ft_strncmp("1234", "1235", -1) < 0);
	/* 5 */ check(ft_strncmp("", "", 42) == 0);
	/* 6 */ check(ft_strncmp("HelloWorld", "HelloWorld", 42) == 0);
	/* 7 */ check(ft_strncmp("HelloWorld", "helloWorld", 42) < 0);
	/* 8 */ check(ft_strncmp("HelloWorld", "HelLoWorld", 42) > 0);
	/* 9 */ check(ft_strncmp("HelloWorld", "HelloWorlD", 42) > 0);
	/* 10 */ check(ft_strncmp("HelloWorld", "HelloWorldX", 42) < 0);
	/* 11 */ check(ft_strncmp("HelloWorld", "HelloWorl", 42) > 0);
	/* 12 */ check(ft_strncmp("", "1", 0) == 0);
	/* 13 */ check(ft_strncmp("1", "", 0) == 0);
	/* 14 */ check(ft_strncmp("", "1", 1) < 0);
	/* 15 */ check(ft_strncmp("1", "", 1) > 0);
	/* 16 */ check(ft_strncmp("", "", 1) == 0);

	/* ohaponiuk */
	/* Check correct behavior for negative char values.
	 * This matches the behavior of libc strncmp.*/
	signed char	str1[] = "test";
	signed char	str2[] = "test";
	size_t		len = strlen((const char *)str1);
	str2[3] = SCHAR_MIN;
	/* 17 */ check(sign(ft_strncmp((const char *)str1, (const char *)str2, len)) == sign(strncmp((const char *)str1, (const char *)str2, len)));
	str2[3] = -42;
	/* 18 */ check(sign(ft_strncmp((const char *)str1, (const char *)str2, len)) == sign(strncmp((const char *)str1, (const char *)str2, len)));

	printf("\n");
}
