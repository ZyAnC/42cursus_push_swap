/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:53:03 by yzheng            #+#    #+#             */
/*   Updated: 2024/09/18 19:00:42 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	init_stacks(t_stacks *s)
{
	s->top_a = -1;
	s->top_b = -1;
}

void	pb(t_stacks *s)
{
	int	i;

	if (s->top_a >= 0)
	{
		s->stack_b[++s->top_b] = s->stack_a[0];
		i = 0;
		while (i < s->top_a)
		{
			s->stack_a[i] = s->stack_a[i + 1];
			i++;
		}
		s->top_a--;
		ft_printf("pb\n");
	}
}
