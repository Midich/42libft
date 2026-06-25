#include "../check.h"
#include "libft.h"
#include <stdio.h>

int main()
{
	printf("ft_isalnum\t");
	/*1*/check(ft_isalnum('a') == 1);
	/*2*/check(ft_isalnum('a' - 1) == 0);
	/*3*/check(ft_isalnum('z') == 1);
	/*4*/check(ft_isalnum('z' + 1) == 0);
	/*5*/check(ft_isalnum('A') == 1);
	/*6*/check(ft_isalnum('A' - 1) == 0);
	/*7*/check(ft_isalnum('Z') == 1);
	/*8*/check(ft_isalnum('Z' + 1) == 0);
	/*9*/check(ft_isalnum('0') == 1);
	/*10*/check(ft_isalnum('0' - 1) == 0);
	/*11*/check(ft_isalnum('9') == 1);
	/*12*/check(ft_isalnum('9' + 1) == 0);
	/*13*/check(ft_isalnum('\t') == 0);
	/*14*/check(ft_isalnum('@') == 0);
	printf("\n");
}
