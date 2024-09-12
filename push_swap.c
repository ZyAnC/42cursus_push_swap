/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:05:08 by yzheng            #+#    #+#             */
/*   Updated: 2024/09/12 15:53:23 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

int	*array_alloc(int size)
{
	int	*res;

	res = malloc(sizeof(int) * size);
	if (!res)
		return (NULL);
	ft_memset (res, -1, sizeof(int));
	return (res);
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

int	main(int ac, char **av)
{
	int			*a;
	int			*b;
	t_stacks	s;

	if (ac <= 2)
		exit(1);
	if (!checkarg(ac, av))
		error();
	init_stacks(&s);
	if (!fill_array(ac, av, &a, &b))
		error();
	is_sort(b, ac - 1, a);
	if (ac == 3)
		ft_printf("sa\n");
	else if (ac == 4)
		sort_3(a, &s);
	else if (ac == 5 || ac == 6)
		sort_4_5(ac, a, b, &s);
	else
		push_swap(&a, &b, ac - 1, &s);
	free(a);
	free(b);
}
