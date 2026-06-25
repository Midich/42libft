#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char addOne(unsigned int i, char c) {return (i + c);}

int main()
{
	printf("ft_strmapi\t");

	char * s = ft_strmapi("1234", addOne);
	/* 1 */ check(!strcmp(s, "1357"));
	/* 2 */ mcheck(s, strlen("1357") + 1); free(s);

	s = ft_strmapi("", addOne);
	/* 3 */ check(!strcmp(s, ""));
	/* 4 */ mcheck(s, strlen("") + 1); free(s);
	printf("\n");
}
