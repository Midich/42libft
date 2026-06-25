#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	printf("ft_strchr\t");
	char s[] = "helloworld";
	/* 1 */ check(ft_strchr(s, 'h') == s);
	/* 2 */ check(ft_strchr(s, 'r') == s + 7);
	/* 3 */ check(ft_strchr(s, 'z') == 0);
	/* 4 */ check(ft_strchr(s, 0) == s + strlen(s));
	/* 5 */ check(ft_strchr(s, 'h' + 256) == s);
	printf("\n");
}
