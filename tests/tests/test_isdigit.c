#include "../check.h"
#include "libft.h"
#include <stdio.h>

int main()
{
	printf("ft_isdigit\t");
	/*1*/check(ft_isdigit('0') == 1);
	/*2*/check(ft_isdigit('0' - 1) == 0);
	/*3*/check(ft_isdigit('9') == 1);
	/*4*/check(ft_isdigit('9' + 1) == 0);
	/*5*/check(ft_isdigit('G') == 0);
	/*6*/check(ft_isdigit('\t') == 0);
	/*7*/check(ft_isdigit('@') == 0);
	printf("\n");
}
