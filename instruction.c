/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:56:29 by yzheng            #+#    #+#             */
/*   Updated: 2024/09/12 15:51:50 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *s)
{
	int	i;

	if (s->top_b >= 0)
	{
		i = s->top_a + 1;
		while (i > 0)
		{
			s->stack_a[i] = s->stack_a[i - 1];
			i--;
		}
		s->stack_a[0] = s->stack_b[s->top_b--];
		s->top_a++;
		ft_printf("pa\n");
	}
}

void	ra(t_stacks *s)
{
	int	i;
	int	temp;

	if (s->top_a > 0)
	{
		temp = s->stack_a[0];
		i = 0;
		while (i < s->top_a)
		{
			s->stack_a[i] = s->stack_a[i + 1];
			i++;
		}
		s->stack_a[s->top_a] = temp;
		ft_printf("ra\n");
	}
}

void	sa(t_stacks *s)
{
	int	temp;

	if (s->top_a > 0)
	{
		temp = s->stack_a[0];
		s->stack_a[0] = s->stack_a[1];
		s->stack_a[1] = temp;
		ft_printf("sa\n");
	}
}

void	sb(t_stacks *s)
{
	int	temp;

	if (s->top_b > 0)
	{
		temp = s->stack_b[0];
		s->stack_b[0] = s->stack_b[1];
		s->stack_b[1] = temp;
		ft_printf("sb\n");
	}
}

void	rra(t_stacks *s)
{
	int	i;
	int	temp;

	if (s->top_a > 0)
	{
		temp = s->stack_a[s->top_a];
		i = s->top_a;
		while (i > 0)
		{
			s->stack_a[i] = s->stack_a[i - 1];
			i--;
		}
		s->stack_a[0] = temp;
		ft_printf("rra\n");
	}
}
