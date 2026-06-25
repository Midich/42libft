#include "../check.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	printf("ft_putnbr_fd\t");

	int fd = open("tripouille", O_RDWR | O_CREAT, 0777);
	ft_putnbr_fd(0, fd);
	lseek(fd, SEEK_SET, 0);
	char s[42] = {0}; read(fd, s, 2);
	/* 1 */ check(!strcmp(s, "0"));
	close(fd);
	unlink("./tripouille");

	fd = open("tripouille", O_RDWR | O_CREAT, 0777);
	ft_putnbr_fd(10, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 3);
	/* 2 */ check(!strcmp(s, "10"));
	close(fd);
	unlink("./tripouille");

	fd = open("tripouille", O_RDWR | O_CREAT, 0777);
	ft_putnbr_fd(2147483647, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 11);
	/* 3 */ check(!strcmp(s, "2147483647"));
	close(fd);
	unlink("./tripouille");

	fd = open("tripouille", O_RDWR | O_CREAT, 0777);
	ft_putnbr_fd(-2147483648, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, s, 12);
	/* 4 */ check(!strcmp(s, "-2147483648"));
	close(fd);
	unlink("./tripouille");

	fd = open("tripouille", O_RDWR | O_CREAT, 0777);
	ft_putnbr_fd(-42, fd);
	lseek(fd, SEEK_SET, 0);
	s[read(fd, s, 4)] = 0;
	/* 5 ipenas */ check(!strcmp(s, "-42"));
	close(fd);
	unlink("./tripouille");
	printf("\n");
}
