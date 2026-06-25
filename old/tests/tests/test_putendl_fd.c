#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	printf("ft_putendl_fd\t");

	int fd = open("tripouille", O_RDWR | O_CREAT);
	ft_putendl_fd((char*)"42", fd);
	lseek(fd, SEEK_SET, 0);
	char s[10] = {0}; read(fd, s, 4);
	/* 1 */ check(!strcmp(s, "42\n"));
	close(fd);
	unlink("./tripouille");
	printf("\n");
}
