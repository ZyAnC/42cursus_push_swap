/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:31:20 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 23:04:35 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>  // For the standard strchr

char    *ft_strchr(const char *s, int c);
 // Assume your function is declared here

int main() {
    const char *str = "tripouille";


    char *result1 = strchr(str, 1024 );
    char *result2 = ft_strchr(str, 1024 );

    printf("Standard strchr: %s\n", result1);
    printf("Your ft_strchr: %s\n", result2);

    // Test for '\0'
    result1 = strchr(str, '\0');
    result2 = ft_strchr(str, '\0');

    printf("Standard strchr (null char): %p\n", (void *)result1);
    printf("Your ft_strchr (null char): %p\n", (void *)result2);

    return 0;
}*/
