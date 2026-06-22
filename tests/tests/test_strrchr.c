#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	printf("ft_strrchr\t");

	char s[] = "HelloWorld";
	char s2[] = "";
	/* 1 */ check(ft_strrchr(s, 'H') == s);
	/* 2 */ check(ft_strrchr(s, 'l') == s + 8);
	/* 3 */ check(ft_strrchr(s, 'd') == s + 9);
	/* 4 */ check(ft_strrchr(s, 'z') == NULL);
	/* 5 */ check(ft_strrchr(s, 0) == s + strlen(s));
	/* 6 */ check(ft_strrchr(s, 'H' + 256) == s);
	char * empty = (char*)calloc(1, 1);
	/* 7 */ check(ft_strrchr(empty, 'V') == NULL);
	free(empty);
	/* 8 */ check(ft_strrchr(s2, 0) == s2);
	printf("\n");
}
