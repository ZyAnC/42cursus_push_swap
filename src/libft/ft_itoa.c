/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:20:44 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/16 12:20:46 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static	int	count_digit(int tmp)
{
	int	digit;

	digit = 1;
	while (tmp / 10 != 0)
	{
		digit++;
		tmp /= 10;
	}
	return (digit);
}

static	char	*malloc_fill(int digit, int space, unsigned int num)
{
	char	*result;

	result = (char *)malloc(digit + space);
	if (result == NULL)
		return (NULL);
	result[digit + space - 1] = '\0';
	while (digit--)
	{
		result[digit + space - 1] = '0' + num % 10;
		num /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int				digit;
	char			*result;
	unsigned int	num;

	num = ft_abs(n);
	digit = count_digit(num);
	if (n < 0)
	{
		result = malloc_fill(digit, 2, num);
		if (!result)
			return (NULL);
		result[0] = '-';
	}
	else
	{
		result = malloc_fill(digit, 1, num);
		if (!result)
			return (NULL);
	}
	return (result);
}
/*
#include <stdio.h>
int main() {
    int test_cases[] = {123, -456, 7890, -12345, 67890};

    for (unsigned long i = 0; i < sizeof(test_cases)
	/ sizeof(test_cases[0]); i++) {
        char *result = ft_itoa(test_cases[i]);
        if (result != NULL) {
            printf("Integer: %d, String: %s\n", test_cases[i], result);
            free(result);
        } else {
            printf("Memory allocation failed for integer: %d\n", test_cases[i]);
        }
    }

    return 0;
}*/
