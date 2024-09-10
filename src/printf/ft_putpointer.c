/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:46:20 by yzheng            #+#    #+#             */
/*   Updated: 2024/08/14 10:54:28 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_puthexpo(uintptr_t nb, int i)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
	{
		i = ft_puthexpo(nb / 16, i);
		if (i == -1)
			return (-1);
		if (write(1, &hex[nb % 16], 1) != 1)
			return (-1);
		i++;
	}
	else if (nb < 16)
	{
		if (write(1, &hex[nb % 16], 1) != 1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putpointer(void *p)
{
	int	i;

	i = 0;
	if (write(1, "0x", 2) != 2)
		return (-1);
	i = ft_puthexpo((uintptr_t)p, i);
	if (i == -1)
		return (-1);
	else
		return (i + 2);
}
