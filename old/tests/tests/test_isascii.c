#include "../check.h"
#include "libft.h"
#include <stdio.h>

int main()
{
	printf("ft_isascii\t");
	/*1*/check(ft_isascii(0) == 1);
	/*2*/check(ft_isascii(127) == 1);
	/*3*/check(ft_isascii(-1) == 0);
	/*4*/check(ft_isascii(128) == 0);
	printf("\n");
}
