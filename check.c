/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:33:25 by yzheng            #+#    #+#             */
/*   Updated: 2024/09/23 11:28:24 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_dup(int *a, int j)
{
	int	cur;

	cur = a[j];
	j--;
	while (j >= 0)
	{
		if (a[j] == cur)
			return (1);
		j--;
	}
	return (0);
}

int	is_digit_str(char *str)
{
	if ((*str == '-' || *str == '+') && *(str + 1))
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_overflow(char *str)
{
	int	num;

	if (ft_strlen(str) > 10)
	{
		num = ft_atoi(str);
		if (num == -1 || num == 0)
			return (1);
	}
	return (0);
}

int	is_valid(char *str)
{
	if (!str)
		return (0);
	if (*str == ' ')
		return (0);
	if (*str == '\0')
		return (0);
	if (!is_digit_str(str))
		return (0);
	if (is_overflow(str))
		return (0);
	return (1);
}

int	checkarg(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_valid(av[i]))
			return (0);
		i++;
	}
	return (1);
}
