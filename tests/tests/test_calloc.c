#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

int main()
{
	printf("ft_calloc\t");

	void * p = ft_calloc(2, 2);
	char e[] = {0, 0, 0, 0};
	/* 1 */ check(!memcmp(p, e, 4));
	/* 2 */ mcheck(p, 4); free(p);
	/* 3 */ check(ft_calloc(SIZE_MAX, SIZE_MAX) == NULL);

	/* @evportel */
	/* The following tests are not supported by the function's documentation.
	 * But some effects returned in the trait by Moulinette so the following
	 * tests were implemented. */
	/* 4 */ check(ft_calloc(INT_MAX, INT_MAX) == NULL);
	/* 5 */ check(ft_calloc(INT_MIN, INT_MIN) == NULL);
	p = ft_calloc(0, 0);
	/* 6 */ check(p != NULL); free(p);
	p = ft_calloc(0, 5);
	/* 7 */ check(p != NULL); free(p);
	p = ft_calloc(5, 0);
	/* 8 */ check(p != NULL); free(p);
	/* 9 */ check(ft_calloc(-5, -5) == NULL);
	p = ft_calloc(0, -5);
	/* 10 */ check(p != NULL); free(p);
	p = ft_calloc(-5, 0);
	/* 11 */ check(p != NULL); free(p);
	/* 12 */ check(ft_calloc(3, -5) == NULL);
	/* 13 */ check(ft_calloc(-5, 3) == NULL);
	printf("\n");
}
