#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	printf("ft_itoa\t");

	char * s = ft_itoa(2147483647);
	/* 1 */ check(!strcmp(s, "2147483647"));
	/* 2 */ mcheck(s, strlen("2147483647") + 1); free(s);

	s = ft_itoa(-2147483648);
	/* 3 */ check(!strcmp(s, "-2147483648"));
	/* 4 */ mcheck(s, strlen("-2147483648") + 1); free(s);

	s = ft_itoa(0);
	/* 5 */ check(!strcmp(s, "0"));
	/* 6 */ mcheck(s, strlen("0") + 1); free(s);
	s = ft_itoa(1);
	/* 7 */ check(!strcmp(s, "1"));
	/* 8 */ mcheck(s, strlen("1") + 1); free(s);
	s = ft_itoa(-1);
	/* 9 */ check(!strcmp(s, "-1"));
	/* 10 */ mcheck(s, strlen("-1") + 1); free(s);

	s = ft_itoa(42);
	/* 11 */ check(!strcmp(s, "42"));
	/* 12 */ mcheck(s, strlen("42") + 1); free(s);
	printf("\n");
}
