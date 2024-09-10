/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:56:13 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 23:40:50 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	slen;

	if (!*to_find)
		return ((char *)str);
	i = 0;
	slen = ft_strlen(str);
	if (len > slen)
		len = slen;
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j < len))
			j++;
		if (!to_find[j])
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
    // Take any two strings
    char s1[] = "GeeksfofGeeks";
    char s2[] = "sfof";
    char* p;

    // Find first occurrence of s2 in s1
    p = ft_strnstr(s1, s1,8);

    // Prints the result
    if (p) {
        printf("String found\n");
        printf("First occurrence of string '%s' in '%s' is "
               "'%s'",
               s2, s1, p);
    }
    else
        printf("String not found\n");

    return 0;
}*/
