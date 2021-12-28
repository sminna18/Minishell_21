/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:47:22 by sminna            #+#    #+#             */
/*   Updated: 2021/12/27 16:11:52 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	preparser_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (!str[i] || str[i] != '\'')
			{
				printf("Imput error: \'\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	preparser_d_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
		{
			i++;
			while (str[i] && (str[i] != '\"' || \
			(str[i - 1] && str[i - 1] == '\\')))
				i++;
			if (!str[i] || str[i] != '\"')
			{
				printf("Imput error: \"\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	preparser_pipe(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|' && str[i + 1] && str[i + 1] == '|')
		{
			printf("syntax error near unexpected token `|'\n");
			return (1);
		}
		if (str[i] == ';' && str[i + 1] && str[i + 1] == ';')
		{
			printf("syntax error near unexpected token `;'\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	preparser_redirect(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '<' && str[i + 1] && str[i + 1] == '>') || \
		(str[i] == '>' && str[i + 1] && str[i + 1] == '<'))
		{
			printf("Imput error: <>\n");
			return (1);
		}
		if ((str[i] == '<' && str[i + 1] && str[i + 1] == '<' && str[i + 2] && \
		str[i + 2] == '<') || (str[i] == '>' && str[i + 1] && str[i + 1] == '>' \
		&& str[i + 2] && str[i + 2] == '>'))
		{
			printf("Imput error: <>\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	preparser(char *str)
{
	if (preparser_quotes(str))
		return (1);
	if (preparser_d_quotes(str))
		return (1);
	if (preparser_pipe(str))
		return (1);
	if (preparser_redirect(str))
		return (1);
	return (0);
}
