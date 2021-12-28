/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:47:07 by sminna            #+#    #+#             */
/*   Updated: 2021/12/27 19:58:38 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	memor_part(t_shell *shell, int i)
{
	if (i == 111)
	{
		shell->pipe_count_max = 0;
		shell->tmp_split_on_off = 0;
		shell->free = 1;
	}
	if (i == 222)
	{
		free(shell->pipes);
		free(shell->flags_for_prog);
		free(shell->start_flag_prog);
		free(shell->count_flag_prog);
		shell->pipes = malloc(sizeof(t_pipes) * shell->func_count);
		shell->flags_for_prog = malloc(sizeof(void **) * shell->func_count);
		shell->start_flag_prog = malloc(sizeof(int) * shell->func_count);
		shell->count_flag_prog = malloc(sizeof(int) * shell->func_count);
	}
}

void	memor_for_pipe_flags(char *str, t_shell *shell, int i, int j)
{
	char	**str1;

	memor_part(shell, 111);
	str1 = ft_split_shell(str, ';', -1, shell);
	memor_part(shell, 222);
	while (++i < shell->func_count)
		shell->flags_for_prog[i] = malloc(sizeof(int) \
		* shell->flags_count + shell->longs + 1);
	i = -1;
	while (++i < shell->func_count)
	{
		shell->str = ft_split_shell(str1[i], '|', -1, shell);
		j = -1;
		while (j++ < shell->pipe_count)
			free(shell->str[j]);
		free(shell->str);
	}
	free(shell->pipes);
	shell->pipes = malloc(sizeof(t_pipes) * shell->pipe_count_max + 20);
	i = -1;
	while (++i < shell->func_count)
		free(str1[i]);
	free(str1);
	tmp_changer(shell);
}

void	write_pipe_flags(t_shell *shell)
{
	int	i;
	int	l;
	int	j;

	i = 0;
	shell->tmp_split_on_off = 0;
	while (i < shell->func_count)
	{
		j = 0;
		l = shell->start_flag_prog[i];
		while (j < shell->count_flag_prog[i])
		{
			shell->flags_for_prog[i][j] = shell->flags[l];
			j++;
			l++;
		}
		i++;
	}
}

char	*find_key(t_shell *shell, char *str1)
{
	int		i;
	int		n;
	char	*key_line;

	n = ft_strlen(str1);
	if (n == 1 && str1[0] == '?')
		return (ft_itoa(shell->error_cod));
	i = 0;
	while (shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], str1, n) == 0 \
		&& shell->envp[i][n] == '=')
		{
			key_line = ft_strdup(shell->envp[i] + n + 1);
			shell->lenght = ft_strlen(key_line);
			return (key_line);
		}
		i++;
	}
	key_line = malloc(2);
	key_line[0] = ' ';
	key_line[1] = '\0';
	return (key_line);
}

void	just_plus(int *a, int *b)
{
	*a = *a + 1;
	*b = *b + 1;
}
