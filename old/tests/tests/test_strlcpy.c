#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	printf("ft_strlcpy\t");

	char src[] = "helloworld";
	char dest[20]; memset(dest, 'A', 20);
	/* 1 */ check(ft_strlcpy(dest, src, 0) == strlen(src) && dest[0] == 'A');
	/* 2 */ check(ft_strlcpy(dest, src, 1) == strlen(src) && dest[0] == 0 && dest[1] == 'A');
	/* 3 */ check(ft_strlcpy(dest, src, 2) == strlen(src) && dest[0] == 'h' && dest[1] == 0  && dest[2] == 'A');
	/* 4 */ check(ft_strlcpy(dest, src, -1) == strlen(src) && !strcmp(src, dest) && dest[strlen(src) + 1] == 'A');
	memset(dest, 'A', 20);
	/* 5 */ check(ft_strlcpy(dest, src, 10) == strlen(src) && !memcmp(src, dest, 9) && dest[9] == 0);
	memset(dest, 'A', 20);
	/* 6 */ check(ft_strlcpy(dest, src, 11) == strlen(src) && !memcmp(src, dest, 11));
	memset(dest, 'A', 20);
	/* 7 */ check(ft_strlcpy(dest, src, 12) == strlen(src) && !memcmp(src, dest, 11));
	memset(dest, 'A', 20);
	/* 8 */ check(ft_strlcpy(dest, "", 42) == 0 && !memcmp("", dest, 1));
	memset(dest, 0, 20);
	/* 9 */ check(ft_strlcpy(dest, "1", 0) == 1 && dest[0] == 0);
	printf("\n");
}
