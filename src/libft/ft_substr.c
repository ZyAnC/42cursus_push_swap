/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:35:42 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/16 10:20:48 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (slen - start < len)
		len = slen - start;
	sub = malloc((len + 1) * sizeof(*s));
	i = 0;
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
/*
#include <stdio.h>
void print_test(char const *s, unsigned int start, size_t len) {
    char *result = ft_substr(s, start, len);
    printf("Result for '%s' starting at %u with length %zu: '%s'\n", 
	s, start, len, result ? result : "NULL");
    free(result);
}

int main() {
    print_test("Hello, world!", 7, 5);
   print_test("Hello", 10, 3);
    print_test("Hello, world!", 7, 20);
    print_test("", 0, 5);
    print_test(NULL, 0, 5);
    return 0;
}*/
