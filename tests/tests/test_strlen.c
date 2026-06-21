#include "../check.h"
#include "libft.h"
#include <stdio.h>

int main()
{
	printf("ft_strlen\t");
	/*1*/check(ft_strlen("") == 0);
	/*2*/check(ft_strlen("galvanize") == 9);
	/*3*/check(ft_strlen("a") == 1);
	printf("\n");
}
