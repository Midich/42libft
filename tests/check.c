// test
#include "check.h"
#include "term_color.h"
#include <stdio.h>

static unsigned int nr_check = 1;

void	check(int success)
{
	if(success)
		printf(FG_GREEN "%u.OK " RESET_ALL, nr_check++);
	else
		printf(FG_RED "%u.KO " RESET_ALL, nr_check++);
}
