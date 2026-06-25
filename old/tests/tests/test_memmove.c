#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	printf("ft_memmove\t");

	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};

	/* 1 */ check(ft_memmove(s0, s, 7) == s0 && !memcmp(s, s0, 7)); //Post 0
	/* 2 */ check(ft_memmove(s, s + 2, 0) && !memcmp(s, sCpy, 7)); //0 move
	/* 3 */ check(ft_memmove(s, s + 2, 2) == s && !memcmp(s, sResult, 7)); //forward
	/* 4 */ check(ft_memmove(sResult + 1, sResult, 2) == sResult + 1 && !memcmp(sResult, sResult2, 7)); //reverse

	printf("\n");
}
