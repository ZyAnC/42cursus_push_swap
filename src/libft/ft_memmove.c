/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:55:02 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 23:03:34 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void	*src, size_t	len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (len == 0)
		return (dst);
	if (d > s)
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	else
	{
		while (len-- && (d || s))
			*d++ = *s++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int main() {
    char str[20] = "1234567890";

    // 将字符串的一部分向后移动一个位置
	ft_memmove(str , str+5, 7);
    printf("%s\n", str);
    return 0;
}*/
