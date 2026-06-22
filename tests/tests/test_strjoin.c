#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	printf("ft_strjoin\t");

	char * s = ft_strjoin("tripouille", "42");
	/* 1 */ check(!strcmp(s, "tripouille42"));
	/* 2 */ mcheck(s, strlen("tripouille") + strlen("42") + 1); free(s);

	s = ft_strjoin("", "42");
	/* 3 */ check(!strcmp(s, "42"));
	/* 4 */ mcheck(s, strlen("") + strlen("42") + 1); free(s);

	s = ft_strjoin("42", "");
	/* 5 */ check(!strcmp(s, "42"));
	/* 6 */ mcheck(s, strlen("42") + strlen("") + 1); free(s);

	s = ft_strjoin("", "");
	/* 7 */ check(!strcmp(s, ""));
	/* 8 */ mcheck(s, strlen("") + strlen("") + 1); free(s);
	printf("\n");
}
