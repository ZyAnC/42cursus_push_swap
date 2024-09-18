/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:51:11 by yzheng            #+#    #+#             */
/*   Updated: 2024/09/18 19:00:31 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	*array_alloc(int size)
{
	int	*res;

	res = malloc(sizeof(int) * size);
	if (!res)
		return (NULL);
	ft_memset (res, -1, sizeof(int));
	return (res);
}

int	array_fill2(int *a, int n, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		a[j] = ft_atoi(av[i]);
		if (is_dup(a, j))
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	fill_array2(int ac, char **av, int **a, int **b)
{
	*a = array_alloc(ac);
	*b = array_alloc(ac);
	if (!*a || !*b || !array_fill2(*a, ac, av) || !array_fill2(*b, ac, av))
	{
		free(*a);
		free(*b);
		return (0);
	}
	return (1);
}

int	array_fill(int *a, int n, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < n)
	{
		a[j] = ft_atoi(av[i]);
		if (is_dup(a, j))
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	fill_array(int ac, char **av, int **a, int **b)
{
	*a = array_alloc(ac - 1);
	*b = array_alloc(ac - 1);
	if (!*a || !*b || !array_fill(*a, ac, av) || !array_fill(*b, ac, av))
	{
		free(*a);
		free(*b);
		return (0);
	}
	return (1);
}
