/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzheng <yzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:53:13 by yzheng            #+#    #+#             */
/*   Updated: 2024/08/14 17:56:48 by yzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static	void	free_result(char **result, int j)
{
	while (j--)
		free(result[j]);
	free(result);
}

static	char	*ftstrndup(const char *src, int n)
{
	char	*dest;
	int		i;

	if (!src)
		return (NULL);
	dest = malloc(n + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[n] = '\0';
	return (dest);
}

int	handle_quotes(t_ParseContext *ctx, char quote)
{
	int	start;

	start = ++(*ctx->i);
	while (ctx->str[*ctx->i] && ctx->str[*ctx->i] != quote)
		(*ctx->i)++;
	if (ctx->str[*ctx->i] == quote)
	{
		ctx->result[*ctx->j] = ftstrndup(ctx->str + start, *ctx->i - start);
		if (!ctx->result[*ctx->j])
		{
			free_result(ctx->result, *ctx->j);
			return (0);
		}
		(*ctx->j)++;
		(*ctx->i)++;
	}
	return (1);
}

int	handle_normal(t_ParseContext *ctx)
{
	int	start;

	start = *ctx->i;
	while (ctx->str[*ctx->i] && ctx->str[*ctx->i] != ctx->charset)
		(*ctx->i)++;
	ctx->result[*ctx->j] = ftstrndup(ctx->str + start, *ctx->i - start);
	if (!ctx->result[*ctx->j])
	{
		free_result(ctx->result, *ctx->j);
		return (0);
	}
	(*ctx->j)++;
	return (1);
}

int	process_string(t_ParseContext *ctx)
{
	while (ctx->str[*ctx->i])
	{
		if (ctx->str[*ctx->i] == '"' || ctx->str[*ctx->i] == '\'')
		{
			if (!handle_quotes(ctx, ctx->str[*ctx->i]))
				return (0);
		}
		else if (ctx->str[*ctx->i] != ctx->charset)
		{
			if (!handle_normal(ctx))
				return (0);
		}
		else
			(*ctx->i)++;
	}
	return (1);
}
