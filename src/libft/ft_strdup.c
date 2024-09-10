/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:48:09 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 22:49:37 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	char	*save;

	dest = malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	save = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (save);
}
/*
#include <stdio.h>
int main()
{
	printf("%s",ft_strdup("aasda"));
}*/
