/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:36:10 by yzheng            #+#    #+#             */
/*   Updated: 2024/09/12 16:02:02 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	set_index(int *a, int *b, int n)
{
	int	left;
	int	right;
	int	i;
	int	cur;

	i = 0;
	while (i < n)
	{
		left = 0;
		right = n - 1;
		while (left <= right)
		{
			cur = left + (right - left) / 2;
			if (a[i] == b[cur])
			{
				a[i] = cur;
				break ;
			}
			else if (b[cur] < a[i])
				left = cur + 1;
			else
				right = cur - 1;
		}
		i++;
	}
}

void	sort_and_index(int *a, int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	set_index(a, tab, size);
}

void	is_sort(int *b, int n, int *a)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (b[i] > b[i - 1])
			i++;
		else
			break ;
	}
	if (i == n)
	{
		free(a);
		free(b);
		exit(0);
	}
}
