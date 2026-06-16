/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ctype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 18:27:46 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/16 13:42:33 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"
#include <ctype.h>
#include <stdio.h>
#include <limits.h>

static void	test(int (*func1)(int), int (*func2)(int))
{
	int	i;
	int	good;
	int	f1;
	int	f2;

	i = -255;
	good = 1;
	while (i <= 255)
	{
		f1 = func1(i);
		f2 = func2(i) != 0;
		if (f1 != f2)
		{
			good = 0;
			printf("\e[0;31mDiscrepancy for %i, func1=%i, func2=%i\e[0m\n",
				i, f1, f2);
		}
		i++;
	}
	if (good)
	{
		printf("\e[0;32mOK\e[0m\n");
	}
}

int	main(void)
{
	printf("ft_isalpha vs isalpha\n");
	test(ft_isalpha, isalpha);
	printf("ft_isdigit vs isdigit\n");
	test(ft_isdigit, isdigit);
	printf("ft_isalnum vs isalnum\n");
	test(ft_isalnum, isalnum);
	printf("ft_isascii vs isascii\n");
	test(ft_isascii, isascii);
	printf("ft_isprint vs isprint\n");
	test(ft_isprint, isprint);
}
