/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:00:36 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 23:05:20 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
	{
		return (ft_strlen(src));
	}
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
int main() {
    // 正常情况
    char dest1[20];
    const char src1[] = "Hello, world!";
    size_t result1 = ft_strlcpy(dest1, src1, sizeof(dest1));
    printf("Result 1: %s, length: %zu\n", dest1, result1);

    // 源字符串长度大于目标字符串长度
    char dest2[5];
    const char src2[] = "Hello, world!";
    size_t result2 = ft_strlcpy(dest2, src2, sizeof(dest2));
    printf("Result 2: %s, length: %zu\n", dest2, result2);

    // 源字符串为空
    char dest3[20];
    const char *src3 = "";
    size_t result3 = ft_strlcpy(dest3, src3, sizeof(dest3));
    printf("Result 3: %s, length: %zu\n", dest3, result3);

    // 目标字符串为空指针
    char *dest4 = NULL;
    const char src4[] = "Hello, world!";
    size_t result4 = ft_strlcpy(dest4, src4, 0);
    printf("Result 4: %zu\n", result4);

    // 目标字符串长度为0
    char dest5[20];
    const char src5[] = "Hello, world!";
    size_t result5 = ft_strlcpy(dest5, src5, 0);
    printf("Result 5: %zu\n", result5);

    return 0;
}
*/
