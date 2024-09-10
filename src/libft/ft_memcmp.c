/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:44:55 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 23:00:13 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
/*
int main() {
    char str1[] = "Hello, world!";
    char str2[] = "Hello, world!";
    char str3[] = "Hello, World!";

    // 测试相等的情况
    printf("Test 1: ");
    if (ft_memcmp(str1, str2, sizeof(str1)) == 0) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    // 测试不等的情况
    printf("Test 2: ");
    if (ft_memcmp(str1, str3, sizeof(str1)) != 0) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    // 测试较小的字节数
    printf("Test 3: ");
    if (ft_memcmp(str1, str3, 5) == 0) { // 前5个字符是相同的
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    return 0;
}*/
