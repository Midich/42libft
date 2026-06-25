#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <strings.h>

int main()
{
	char test_case[100];
	int i;
	bzero(test_case, 100);
	printf("ft_memset\t");
	ft_memset(test_case, 'A', 0);
	/*1*/check(test_case[0] == 0);
	ft_memset(test_case, 'A', 42);
	i = 0;
	while (i < 100 && test_case[i] == 'A')
		i++;
	/*2*/check(i == 42 && test_case[42] == 0);
	printf("\n");
}
