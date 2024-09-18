/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:56:34 by yzheng            #+#    #+#             */
/*   Updated: 2024/09/18 19:00:40 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_4_5_util(t_stacks *s)
{
	if (s->stack_b[0] == 0)
		sb(s);
	if (s->stack_a[2] != 4)
	{
		if (s->stack_a[0] == 4)
			ra(s);
		else
			rra(s);
	}
	if (s->stack_a[0] > s->stack_a[1])
		sa(s);
	pa(s);
	pa(s);
	if (s->stack_a[0] > s->stack_a[1])
		sa(s);
}

void	sort_4_5(int ac, int *a, int *b, t_stacks *s)
{
	int	i;

	i = 0;
	sort_and_index(a, b, ac - 1);
	while (i < ac - 1)
		s->stack_a[++s->top_a] = a[i++];
	while (s->top_b <= 0)
	{
		if (s->stack_a[0] == 0 || s->stack_a[0] == 1)
			pb(s);
		else
			ra(s);
	}
	sort_4_5_util(s);
}

void	sort_3(int *a, t_stacks *s)
{
	s->top_a = 2;
	if (a[0] < a[1] && a[0] < a[2] && a[1] > a[2])
	{
		sa(s);
		ra(s);
	}
	else if (a[0] < a[1] && a[0] > a[2] && a[1] > a[2])
		rra(s);
	else if (a[0] > a[1] && a[0] > a[2] && a[1] > a[2])
	{
		sa(s);
		rra(s);
	}
	else if (a[0] > a[1] && a[0] > a[2] && a[1] < a[2])
		ra(s);
	else if (a[0] > a[1] && a[0] < a[2] && a[1] < a[2])
		sa(s);
}

void	radix_sort(int n, t_stacks *s)
{
	int	max_index;
	int	bits;
	int	i;
	int	j;

	bits = 0;
	max_index = n - 1;
	while (max_index >> bits)
		bits++;
	i = -1;
	while (++i < bits)
	{
		j = 0;
		while (j < n)
		{
			if (((s->stack_a[0] >> i) & 1) == 1)
				ra(s);
			else
				pb(s);
			j++;
		}
		while (s->top_b >= 0)
			pa(s);
	}
}

void	push_swap(int **a, int **b, int n, t_stacks *s)
{
	int	i;

	i = 0;
	sort_and_index(*a, *b, n);
	while (i < n)
		s->stack_a[++s->top_a] = (*a)[i++];
	radix_sort(n, s);
}
