/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:28:21 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 22:59:26 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t	n)
{
	const unsigned char	*p;

	p = (const unsigned char *)s;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
/*
int main() {
    const char *str = "Hello, World!";
    char target = 'W';
    char not_found = 'x';
    size_t len = 13;  // Length of the string including the null terminator

    // Test 1: Searching for a character that exists
    char *result = memchr(str, target, len);
    if (result) {
        printf("Character '%c' found at position: %ld\n", target, result - str);
    } else {
        printf("Character '%c' not found\n", target);
    }

    // Test 2: Searching for a character that does not exist
    result = memchr(str, not_found, len);
    if (result) {
        printf("Character '%c' found at position: %ld\n",
	   	not_found, result - str);
    } else {
        printf("Character '%c' not found\n", not_found);
    }

    // Test 3: Testing with binary data
    unsigned char data[] = {0x01, 0x02, 0xFF, 0x04, 0x05};
    result = (char *)memchr(data, 0xFF, sizeof(data));
    if (result) {
        printf("Byte '0xFF' found at position: %ld\n", result - (char *)data);
    } else {
        printf("Byte '0xFF' not found\n");
    }

    return 0;
}*/
