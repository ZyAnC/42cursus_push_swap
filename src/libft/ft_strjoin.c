/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:07:16 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/16 11:20:23 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	len1;
	size_t	len2;
	char	*str;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	else if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = len1 + len2;
	str = malloc((len + 1) * sizeof(*s1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2 + 1);
	return (str);
}
/*
#include <stdio.h>
void print_strjoin_result(char const *s1, char const *s2) {
    char *result = ft_strjoin(s1, s2);
    printf("Joining [%s] and [%s]: Result = [%s]\n", s1 ? s1 : "NULL",
   	s2 ? s2 : "NULL", result ? result : "NULL");
    free(result); // 确保释放分配的内存
}
int main() {
    // 正常情况
    print_strjoin_result("Hello", " World");

    // s1 是空字符串
    print_strjoin_result("", "World");

    // s2 是空字符串
    print_strjoin_result("Hello", "");

    // s1 为 NULL
    print_strjoin_result(NULL, "World");

    // s2 为 NULL
    print_strjoin_result("Hello", NULL);

    // 两者都为 NULL
    print_strjoin_result(NULL, NULL);

    return 0;
}*/
