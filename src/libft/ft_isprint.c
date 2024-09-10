/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:44:11 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 22:57:59 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
/*
#include <stdio.h>
int main() {

    char c = 'a';
    if (ft_isprint(c)) {
        printf("The character %c is an alphabet.\n", c);
    } else {
        printf("The character %c is not an alphabet.\n", c);
    }

    c = '-1';
    if (ft_isprint(c)) {
        printf("The character %c is an alphabet.\n", c);
    } else {
        printf("The character %c is not an alphabet.\n", c);
    }

    return 0;
}*/
