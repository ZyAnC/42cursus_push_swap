/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:05:08 by yzheng            #+#    #+#             */
/*   Updated: 2024/09/25 11:14:38 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_model2(int ac, char **av)
{
	int			*a;
	int			*b;
	t_stacks	s;

	init_stacks(&s);
	if (!fill_array2(ac - 1, av, &a, &b))
		error();
	is_sort2(b, ac - 1, a, av);
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
	ac = ac - 2;
	while (ac >= 0)
		free(av[ac--]);
	free(av);
}

void	main_model(int ac, char **av)
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

int	checkstrarg(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (!is_valid(av[i]))
			return (0);
		i++;
	}
	return (1);
}

void	checkall(int i, char **arg)
{
	if (!checkstrarg(i, arg))
	{
		i--;
		while (i >= 0)
			free(arg[i--]);
		free(arg);
		error();
	}
	if (i == 1)
	{
		free(arg[0]);
		free(arg);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	char	**arg;
	int		i;

	if (ac < 2)
		exit(0);
	else if (ac == 2)
	{
		arg = ft_split(av[1], ' ');
		if (!arg)
			error();
		i = 0;
		while (arg[i] != NULL)
			i++;
		checkall(i, arg);
		main_model2(i + 1, arg);
	}
	else
		main_model(ac, av);
}
