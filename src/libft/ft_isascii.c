/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:41:19 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 22:57:13 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int main() {
    int chars[] = {65, 128, -1, 0, 127, 32, 120};
    int num_chars = sizeof(chars) / sizeof(chars[0]);

    for (int i = 0; i < num_chars; i++) {
        if (ft_isascii(chars[i])) {
            printf("The character %d is an ASCII character.\n", chars[i]);
        } else {
            printf("The character %d is not an ASCII character.\n", chars[i]);
        }
    }

    return 0;
}*/
