#include "../check.h"
#include "libft.h"
#include <stdio.h>

int main()
{
	printf("ft_isalpha\t");
	/*1*/check(ft_isalpha('a') == 1);
	/*2*/check(ft_isalpha('a' - 1) == 0);
	/*3*/check(ft_isalpha('z') == 1);
	/*4*/check(ft_isalpha('z' + 1) == 0);
	/*5*/check(ft_isalpha('A') == 1);
	/*6*/check(ft_isalpha('A' - 1) == 0);
	/*7*/check(ft_isalpha('Z') == 1);
	/*8*/check(ft_isalpha('Z' + 1) == 0);
	/*9*/check(ft_isalpha('4') == 0);
	/*10*/check(ft_isalpha('\t') == 0);
	/*11*/check(ft_isalpha('@') == 0);
	printf("\n");
}
