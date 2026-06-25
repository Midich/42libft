#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	printf("ft_memcpy\t");

	char dest[100];
	memset(dest, 'A', 100);
	ft_memcpy(dest, "helloworld", 0);
	/* 1 */ check(dest[0] == 'A');
	char *rtn = (char *)ft_memcpy(dest, NULL, 0);
	/* 2 */ check(rtn == dest && dest[0] == 'A');
	char src[] = {0, 0};
	ft_memcpy(dest, src, 2);
	int i = 0;
	while (i < 100 && dest[i] == 0)
		i++;
	/* 3 */ check(i == 2 && dest[2] == 'A');
	printf("\n");
}
