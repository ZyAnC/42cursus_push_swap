/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmemcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:26:00 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 23:10:41 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (n == 0)
		return (dst);
	while (n-- && (d || s))
		*d++ = *s++;
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

void check(int condition, const char* test_description) {
    if (condition) {
        printf("%s: PASS\n", test_description);
    } else {
        printf("%s: FAIL\n", test_description);
    }
}

void showLeaks() {
    // 这里通常空着，除非你有特殊的内存泄漏检测工具
}

int main(void) {


   char *rtn = (char *)ft_memcpy(NULL, NULL, 2);
    printf("my%s",rtn);

	 char *rtn1 = (char *)memcpy(NULL, NULL, 2);
    printf("st%s",rtn1);
    showLeaks();


    return 0;
}*/
