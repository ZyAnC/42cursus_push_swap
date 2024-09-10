/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:13:56 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 22:53:26 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*s, size_t	n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = 0;
}
/*
#include <stdio.h>
#include <string.h>
int main() {
    char buffer[10];


    ft_bzero(buffer, sizeof(buffer));


    for (unsigned long i = 0; i < sizeof(buffer); i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    return 0;
}*/
