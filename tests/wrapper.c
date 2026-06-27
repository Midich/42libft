#include <stddef.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void	*__wrap_malloc(size_t c)
{
	return (0);
}
#pragma GCC diagnostic pop
