/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:54:06 by yzheng            #+#    #+#             */
/*   Updated: 2024/04/15 22:54:10 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t			total;
	unsigned char	*memory;

	total = num * size;
	if (num > 0 && size > 0 && (total / size != num))
		return (NULL);
	memory = malloc(total);
	if (memory != NULL)
		ft_memset(memory, 0, total);
	return (memory);
}
