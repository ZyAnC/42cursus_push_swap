/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:26:19 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 23:09:00 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
/*
#include <stdio.h>
int main() {

    char test_cases[] = {'a', 'A', 'z', 'Z', '1', ' '};


    for (unsigned long i = 0; i < sizeof(test_cases); ++i) {
        printf("Character: %c, Uppercase: %c\n", 
		test_cases[i], ft_tolower(test_cases[i]));
    }

    return 0;
}*/
