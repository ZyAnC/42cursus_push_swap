/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:37:27 by yzheng            #+#    #+#             */
/*   Updated: 2024/09/12 17:06:55 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int main() {
    char test_cases[] = {'a', 'Z', '5', '%', '\n', ' '};
	int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_cases; i++) {
        char c = test_cases[i];
        if (ft_isalnum(c)) {
            printf("The character '%c' is alphanumeric.\n", c);
        } else {
            printf("The character '%c' is not alphanumeric.\n", c);
        }
    }

    return 0;
}*/
