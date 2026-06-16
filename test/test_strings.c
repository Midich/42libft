/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:32:39 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/16 14:49:50 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"
#include <string.h>
#include <stdio.h>

void	test_strlen(void)
{
	int			i;
	int			ok;
	const char	*tests[] = {"", "aifunnigweoi", "jask  nkdjwd ",
		"293nnv883bbia9    938n", 0};

	ok = 1;
	i = 0;
	while (tests[i])
	{
		if (strlen(tests[i]) != ft_strlen(tests[i]))
		{
			printf("\e[0;31mError %s, strlen %lu, ft_strlen %lu\e[0m\n",
				tests[i], strlen(tests[i]), ft_strlen(tests[i]));
			ok = 0;
		}
		i++;
	}
	if (ok)
	{
		printf("\e[0;32mOK\e[0m\n");
	}
}

static int	cmp_array(int *arr1, int *arr2, unsigned long int n)
{
	unsigned long int	i;

	i = 0;
	while (i < n)
	{
		if (arr1[i] < arr2[i])
			return (-1);
		else if (arr1[i] > arr2[i])
			return (1);
		i++;
	}
	return (0);
}

void	test_memset(void)
{
	int	ft_t[100];
	int	t[100];
	int	ok;

	ok = 1;
	memset(ft_t, 0, 100 * sizeof(int));
	memset(t, 0, 100 * sizeof(int));
	ft_memset(ft_t, 'a', 30 * sizeof(int));
	memset(t, 'a', 30 * sizeof(int));
	if (cmp_array(ft_t, t, 100))
	{
		ok = 0;
		printf("\e[0;31mError for memset 'a' 30\e[0m\n");
	}
	ft_memset(ft_t, 100, 29 * sizeof(int));
	memset(t, 100, 29 * sizeof(int));
	if (cmp_array(ft_t, t, 100))
	{
		ok = 0;
		printf("\e[0;31mError for memset 'a' 30\e[0m\n");
	}
	if (ok)
		printf("\e[0;32mOK\e[0m\n");
}

int	main(void)
{
	printf("ft_strlen\n");
	test_strlen();
	printf("ft_memset\n");
	test_memset();
}
