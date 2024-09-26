/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:05:53 by yzheng            #+#    #+#             */
/*   Updated: 2024/09/26 17:15:22 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./src/libft/libft.h"
# include "./src/printf/printf.h"
# include <stdlib.h>

typedef struct stack
{
	int	stack_a[501];
	int	stack_b[501];
	int	top_a;
	int	top_b;
}	t_stacks;

typedef struct s_ms
{
	char	**av;
	int		a;
}	t_ms;

t_ms	*ms(void);
void	error(void);
int		is_valid(char *str);
int		checkarg(int ac, char **av);
int		is_overflow(char *str);
int		is_digit_str(char *str);
int		is_dup(int *a, int j);
void	is_sort2(int *b, int n, int *a, char **av);
void	is_sort(int *b, int n, int *a);
void	pb(t_stacks *s);
void	pa(t_stacks *s);
void	ra(t_stacks *s);
void	sa(t_stacks *s);
void	sb(t_stacks *s);
void	rra(t_stacks *s);
int		fill_array2(int ac, char **av, int **a, int **b);
int		fill_array(int ac, char **av, int **a, int **b);
void	radix_sort(int n, t_stacks *s);
void	sort_3(int *a, t_stacks *s);
void	sort_4_5(int ac, int *a, int *b, t_stacks *s);
void	push_swap(int **a, int **b, int n, t_stacks *s);
void	sort_and_index(int *a, int *tab, int size);
void	set_index(int *a, int *b, int n);
void	init_stacks(t_stacks *s);
#endif
