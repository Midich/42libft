#include "../check.h"
#include "libft.h"
#include <stdio.h>

int main()
{
	printf("ft_atoi\t");

	/* 1 */ check(ft_atoi("\t\n\v\f\r " "1") == 1);
	/* 2 */ check(ft_atoi("\t\n\v\f\r " "a1") == 0);
	/* 3 */ check(ft_atoi("--1") == 0);
	/* 4 */ check(ft_atoi("++1") == 0);
	/* 5 */ check(ft_atoi("+1") == 1);
	/* 6 */ check(ft_atoi("-1") == -1);
	/* 7 */ check(ft_atoi("0") == 0);
	/* 8 */ check(ft_atoi("\t\n\v\f\r ""+42lyon") == 42);
	/* 9 */ check(ft_atoi("+101") == 101);
	/* 10 */ check(ft_atoi("2147483647") == 2147483647);
	/* 11 */ check(ft_atoi("-2147483648") == -2147483648);
	/* 12 */ check(ft_atoi("-+42") == 0);
	/* 13 */ check(ft_atoi("+-42") == 0);
	/* 14 */ check(ft_atoi("+""\t\n\v\f\r ""42") == 0);
	/* 15 */ check(ft_atoi("-""\t\n\v\f\r ""42") == 0);
	/* 16 */ check(ft_atoi("1""\t\n\v\f\r ""42") == 1);
	/* 17 */ check(ft_atoi("-1""\t\n\v\f\r ""42") == -1);
	printf("\n");
}
