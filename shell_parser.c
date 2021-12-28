/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:47:19 by sminna            #+#    #+#             */
/*   Updated: 2021/12/27 19:11:05 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parser_dollar(char *str, int *i, t_shell *shell)
{
	int		j;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	j = *i;
	*i = *i + 1;
	while (str[*i] == '_' || (str[*i] >= 65 && str[*i] <= 90) || (str[*i] >= 97 \
	&& str[*i] <= 122) || (str[*i] >= 48 && str[*i] <= 57) || str[*i] == '?')
		*i = *i + 1;
	str1 = ft_substr(str, j + 1, *i - j - 1);
	str2 = find_key(shell, str1);
	free (str1);
	str1 = ft_substr(str, 0, j);
	str3 = ft_strdup(str + *i);
	str4 = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	str1 = ft_strjoin(str4, str3);
	free(str3);
	free(str4);
	free(str);
	*i = j + shell->lenght;
	return (str1);
}

char	*parser_slesh(char *str, int *i)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = ft_substr(str, 0, *i);
	str2 = ft_strdup(str + *i + 1);
	str3 = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	free(str);
	*i = *i + 1;
	return (str3);
}

char	*parser_quotes2(char *str, int *i, t_shell *shell, int w)
{
	char	*str1;
	char	*str2;
	char	*str3;

	shell->tmp_split2 = *i;
	while (str[++*i] && w)
	{
		if (str[*i] == '\"')
			w = 0;
		if (str[*i] == '\\' && str[*i + 1] && (str[*i + 1] == '\\' \
		|| str[*i + 1] == '\"' || str[*i + 1] == '$'))
			str = parser_slesh(str, i);
		if (str[*i] == '$')
			str = parser_dollar(str, i, shell);
	}
	str1 = ft_substr(str, 0, shell->tmp_split2);
	str2 = ft_substr(str, shell->tmp_split2 + 1, *i - shell->tmp_split2 - 2);
	str3 = ft_strjoin(str1, str2);
	double_free(str1, str2);
	str1 = ft_strdup(str + *i);
	str2 = ft_strjoin(str3, str1);
	double_free(str3, str1);
	free(str);
	return (str2);
}

char	*parser_quotes(char *str, int *i, int w)
{
	int		j;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	j = *i;
	while (str[++*i] && w)
	{
		if (str[*i] == '\'')
			w = 0;
	}
	str1 = ft_substr(str, 0, j);
	str2 = ft_substr(str, j + 1, *i - j - 2);
	str3 = ft_strdup(str + *i);
	str4 = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	str1 = ft_strjoin(str4, str3);
	free(str4);
	free(str3);
	free(str);
	*i = *i - 2;
	return (str1);
}

char	*shell_parser(char *str, t_shell *shell)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] && str[i] == '\'')
			str = parser_quotes(str, &i, 1);
		if (str[i] && str[i] == '\\')
			str = parser_slesh(str, &i);
		if (str[i] && str[i] == '\"')
		{
			str = parser_quotes2(str, &i, shell, 1);
			i = i - 2;
		}
		if (str[i] && str[i] == '$')
			str = parser_dollar(str, &i, shell);
		if (str[i] && (str[i] == ';' || str[i] == '|' ))
			shell->flags[i] = 1;
	}
	return (str);
}
	// str1 = ft_substr(str, 0, j);
	// str2 = ft_substr(str, j + 1, *i - j - 2);
	// str3 = ft_strdup(str + *i);
	// str4 = ft_strjoin(str1, str2);
	// free(str1);
	// free(str2);
	// str1 = ft_strjoin(str4, str3);
	// free(str4);
	// free(str3);
	// free(str);
