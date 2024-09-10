/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:48:06 by yzheng            #+#    #+#             */
/*   Updated: 2024/08/14 17:44:18 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	checkset(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	len;
	size_t	start;
	size_t	end;
	int		i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	start = 0;
	len = ft_strlen(s1);
	while (s1[start] && checkset(set, s1[start]))
		start++;
	if (start == len)
		return (ft_strdup(""));
	end = len - 1;
	while (end > start && checkset(set, s1[end]))
		end--;
	s2 = malloc ((end - start + 2) * sizeof(*s1));
	if (s2 == NULL)
		return (NULL);
	while (start <= end)
		s2[i++] = s1[start++];
	s2[i] = '\0';
	return (s2);
}
