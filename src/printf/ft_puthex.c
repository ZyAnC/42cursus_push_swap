/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:18:22 by yzheng            #+#    #+#             */
/*   Updated: 2024/05/07 21:36:05 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_puthexrec(unsigned int nb, char hex[], int i)
{
	if (nb >= 16)
	{
		i = ft_puthexrec(nb / 16, hex, i);
		if (i == -1)
			return (-1);
	}
	if (write(1, &hex[nb % 16], 1) != 1)
		return (-1);
	return (++i);
}

int	ft_puthex(int nbr, char hex[])
{
	int	i;

	i = 0;
	i = ft_puthexrec((unsigned int)nbr, hex, i);
	if (i == -1)
		return (-1);
	return (i);
}
