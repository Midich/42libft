#include "../check.h"
#include "libft.h"
#include <stdio.h>

int main()
{
	printf("ft_strnstr\t");

	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	char * empty = (char*)"";
	/* 1 */ check(ft_strnstr(haystack, needle, 0) == 0);
	/* 2 */ check(ft_strnstr(haystack, needle, -1) == haystack + 1);
	/* 3 */ check(ft_strnstr(haystack, "a", -1) == haystack);
	/* 4 */ check(ft_strnstr(haystack, "c", -1) == haystack + 4);
	/* 5 */ check(ft_strnstr(empty, "", -1) == empty);
	/* 6 */ check(ft_strnstr(empty, "", 0) == empty);
	/* 7 */ check(ft_strnstr(empty, "hello", -1) == 0);
	/* 8 */ check(ft_strnstr(haystack, "aaabc", 5) == haystack);
	/* 9 */ check(ft_strnstr(empty, "12345", 5) == 0);
	/* 10 */ check(ft_strnstr(haystack, "abcd", 9) == haystack + 5);
	/* 11 */ check(ft_strnstr(haystack, "cd", 8) == NULL);
	/* 12 */ check(ft_strnstr(haystack, "a", 1) == haystack);
	/* 13 */ check(ft_strnstr("1", "a", 1) == NULL);
	/* 14 */ check(ft_strnstr("22", "b", 2) == NULL);
	/* 15 */ check(ft_strnstr("22", "22", 3) != NULL);
	/* 16 */ check(ft_strnstr(haystack, "", 0) == haystack);
	printf("\n");
}
