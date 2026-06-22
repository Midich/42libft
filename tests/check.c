// test
#include "check.h"
#include "term_color.h"
#include <stdio.h>
#include <malloc.h>

static unsigned int nr_check = 1;

void	check(int success)
{
	if(success)
		printf(FG_GREEN "%u.OK " RESET_ALL, nr_check++);
	else
		printf(FG_RED "%u.KO " RESET_ALL, nr_check++);
}

void mcheck(void * p, size_t required_size)
{
	int success = malloc_usable_size(p) == required_size;

	if(success)
		printf(FG_GREEN "%u.MOK " RESET_ALL, nr_check++);
	else
		printf(FG_RED "%u.MKO " RESET_ALL, nr_check++);
}
