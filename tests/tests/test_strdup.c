#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	printf("ft_strdup\t");

	char * s = ft_strdup((char*)"Hello");
	/* 1 */ check(!strcmp(s, "Hello"));
	/* 2 */ mcheck(s, strlen("Hello") + 1); free(s);

	s = ft_strdup((char*)"");
	/* 3 */ check(!strcmp(s, ""));
	/* 4 */ mcheck(s, 1); free(s);
	printf("\n");
}
