/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:13:33 by yzheng            #+#    #+#             */
/*   Updated: 2024/05/07 21:21:08 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_putnbrrec(int nb, int i)
{
	if (nb == -2147483648)
	{
		if (write(1, "-2147483648", 11) != 11)
			return (-1);
		return (11);
	}
	if (nb < 0)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		i++;
		nb = -nb;
	}
	if (nb > 9)
	{
		i = ft_putnbrrec(nb / 10, i);
		if (i == -1)
			return (-1);
	}
	if (ft_putchar(nb % 10 + '0') != 1)
		return (-1);
	return (++i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	return (ft_putnbrrec(nb, i));
}
