#include "../check.h"
#include "libft.h"
#include <stdio.h>

int main()
{
	printf("ft_memcmp\t");

	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
	/* 1 */ check(!ft_memcmp(s, sCpy, 4));
	/* 2 */ check(!ft_memcmp(s, s2, 0));
	/* 3 */ check(ft_memcmp(s, s2, 1) > 0);
	/* 4 */ check(ft_memcmp(s2, s, 1) < 0);
	/* 5 */ check(ft_memcmp(s2, s3, 4) != 0);
	printf("\n");
}
