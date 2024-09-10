/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:04:52 by yzheng            #+#    #+#             */
/*   Updated: 2024/05/07 21:37:39 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_putnbrrec(unsigned int nb, int i)
{
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

int	ft_putuint(unsigned int nb)
{
	int	i;

	i = 0;
	return (ft_putnbrrec(nb, i));
}
