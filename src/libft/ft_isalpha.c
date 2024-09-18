/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:26:22 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 22:55:11 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}
/*
#include <stdio.h>
int main() {
 
    char c = 'a';
    if (ft_isalpha(c)) {
        printf("The character %c is an alphabet.\n", c);
    } else {
        printf("The character %c is not an alphabet.\n", c);
    }

    c = '1';
    if (ft_isalpha(c)) {
        printf("The character %c is an alphabet.\n", c);
    } else {
        printf("The character %c is not an alphabet.\n", c);
    }

    return 0;
}*/
