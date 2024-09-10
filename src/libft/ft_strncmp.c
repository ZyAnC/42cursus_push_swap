/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:59:07 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 23:11:19 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*s1 && *s2 && i < n)
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1++;
		s2++;
		i++;
	}
	if (i < n && ((!(*s1) && *s2) || (*s1 && !*s2)))
	{
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}

/*
#include <stdio.h>
int main() {
  char str1[] = "aa", str2[] = "", str3[] = "abcaaab", str4[] = "abcaaaa";
  int result;
  result = ft_strncmp(str1, str2,3);
  printf("ft_strncmp(str1, str2) = %d\n", result);
  result = ft_strncmp(str1, str3,6);
  printf("ft_strncmp(str1, str3) = %d\n", result);
  result = ft_strncmp(str1, str4,6);
  printf("ft_strncmp(str1, str4) = %d\n", result);
  return 0;
}*/
