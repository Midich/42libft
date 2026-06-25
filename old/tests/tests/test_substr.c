#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	printf("ft_substr\t");

	char * s = ft_substr("tripouille", 0, 42000);
	/* 1 */ check(!strcmp(s, "tripouille"));
	/* 2 */ mcheck(s, strlen("tripouille") + 1); free(s);

	s = ft_substr("tripouille", 1, 1);
	/* 3 */ check(!strcmp(s, "r"));
	/* 4 */ mcheck(s, 2); free(s);

	s = ft_substr("tripouille", 100, 1);
	/* 5 */ check(!strcmp(s, ""));
	/* 6 */ mcheck(s, 1); free(s);

	char * str = strdup("1");
	s = ft_substr(str, 42, 42000000);
	/* 7 */ check(!strcmp(s, ""));
	/* 8 */ mcheck(s, 1); free(s); free(str);

	str = strdup("0123456789");
	s = ft_substr(str, 9, 10);
	/* 9  mbueno-g */ check(!strcmp(s, "9"));
	/* 10  mbueno-g */ mcheck(s, 2); free(s); free(str);

	s = ft_substr("42", 0, 0);
	/* 11  fcaquard */ check(!strcmp(s, ""));
	/* 12  fcaquard */ mcheck(s, 1); free(s);

	s = ft_substr("BONJOUR LES HARICOTS !", 8, 14);
	/* 13  dfarhi */ check(!strcmp(s, "LES HARICOTS !"));
	/* 14  dfarhi */ mcheck(s, 15); free(s);

	s = ft_substr("test", 1, 2);
	/* 15  dfarhi */ check(!strcmp(s, "es"));
	/* 16  dfarhi */ mcheck(s, 3); free(s);
	printf("\n");
}
