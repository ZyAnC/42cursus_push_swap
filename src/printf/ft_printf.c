/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:34:37 by yzheng            #+#    #+#             */
/*   Updated: 2024/05/08 13:10:20 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	checkbase(char c, va_list ap)
{
	char	*hex1;
	char	*hex2;

	hex1 = "0123456789abcdef";
	hex2 = "0123456789ABCDEF";
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putpointer(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putuint(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(ap, int), hex1));
	else if (c == 'X')
		return (ft_puthex(va_arg(ap, int), hex2));
	return (0);
}

static int	pprotection(char c, va_list ap)
{
	if (c != '%')
		return (checkbase(c, ap));
	else
		return (write(1, &c, 1));
}

static int	countag(const char *str, va_list ap, int count)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (-1);
			j = pprotection(str[++i], ap);
			if (j == -1)
				return (-1);
			count += j;
		}
		else
		{
			if (write(1, &str[i], 1) != 1)
				return (-1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, str);
	count = countag(str, ap, count);
	va_end(ap);
	return (count);
}
