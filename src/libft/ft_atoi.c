/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:39:28 by yzheng            #+#    #+#             */
/*   Updated: 2024/09/26 17:17:14 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "./libft.h"
#include <stdio.h>
#include "../../push_swap.h"

static void	fterror(void)
{
	int	i;

	i = 0;
	if (ms()->a == 1)
	{
		while (ms()->av[i] != NULL)
			i++;
		i--;
		while (i >= 0)
			free(ms()->av[i--]);
		free(ms()->av);
	}
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ((*str >= '0' && *str <= '9'))
	{
		result = result * 10 +(*str - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			fterror();
		str++;
	}
	return ((int)(result * sign));
}

/*#include <stdio.h>
int main (){
	char *ss = {" + 2"};
	printf("%d",atoi(ss));
	return 0;
}*/
