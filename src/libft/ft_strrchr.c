/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:55:16 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 23:17:05 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*d;
	size_t		len;

	d = NULL;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (s[len] == (char)c)
		{
			d = &s[len];
			return ((char *)d);
		}
	}
	return ((char *)d);
}
/*
#include <stdio.h>
#include <string.h>
int main() {
    char    str3[] = "";
	char	*str;
    if (!(str = ft_strrchr(str3, '\0')))
        printf("%s",str);
    else
    {
        printf("%s",str);
        if (str != str3)
             printf("a");
    }
}*/
