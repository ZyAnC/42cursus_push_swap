/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:19:36 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 23:12:35 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
#include <stdio.h>
int main() {

    char test_cases[] = {'a', 'A', 'z', 'Z', '1', ' '};


    for (unsigned long i = 0; i < sizeof(test_cases); ++i) {
        printf("Character: %c, Uppercase: %c\n",
		test_cases[i], ft_toupper(test_cases[i]));
    }

    return 0;
}*/
