#include "../check.h"
#include "libft.h"
#include <stdio.h>

int main()
{
	printf("ft_isprint\t");
	/*1*/check(ft_isprint(' ') == 1);
	/*2*/check(ft_isprint(' ' - 1) == 0);
	/*3*/check(ft_isprint('~') == 1);
	/*4*/check(ft_isprint('~' + 1) == 0);
	printf("\n");
}
