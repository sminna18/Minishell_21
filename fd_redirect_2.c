/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_redirect_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:39:59 by sminna            #+#    #+#             */
/*   Updated: 2021/12/26 14:33:32 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_find_file_name(char *str, t_shell *shell, int l)
{
	int		i;
	int		j;
	char	*str2;

	while (str[l] == ' ')
		l++;
	i = l;
	j = 0;
	while (str[i] && str[i] != ' ')
		just_plus(&i, &j);
	shell->n = i + shell->j;
	str2 = malloc(j + 1);
	if (!str2)
		printf("malloc error\n");
	if (!str2)
		return (NULL);
	ft_bzero(str2, (j + 1));
	i = l;
	l = 0;
	while (str[i] && str[i] != ' ')
	{
		str2[l] = str[i];
		just_plus(&i, &l);
	}
	return (str2);
}

int	gnl_light(char **str)
{
	char	s[4096];
	char	r;
	int		i;
	int		x;

	i = 0;
	x = 1;
	ft_bzero(s, 4096);
	while (x > 0)
	{
		x = read(0, &r, 1);
		if (x > 0 && r != '\n')
			s[i] = r;
		if (x > 0 && r == '\n')
		{
			*str = s;
			return (1);
		}
		i++;
	}
	*str = s;
	return (0);
}

int	read_for_redirect(t_shell *shell, char *str, int j, int x)
{
	int		l;
	int		y;
	int		pipefd[2];
	char	*gnl;

	if (pipe(pipefd) == -1)
		printf ("pipe error\n");
	if (pipe(pipefd) == -1)
		return (1);
	while (x)
	{
		l = 0;
		y = gnl_light(&gnl);
		write(pipefd[1], gnl, ft_strlen(gnl));
		write(pipefd[1], &"\n", 1);
		l = ft_strlen(gnl);
		if (j > l)
			l = j;
		if (!ft_strncmp(gnl, str, l))
			x = 0;
	}
	close(pipefd[1]);
	shell->pipes[shell->i].fd_in = pipefd[0];
	return (0);
}

int	fd_redirect_input_1(t_shell *shell)
{
	char	*str;
	char	*str1;
	char	*str2;

	if (shell->pipes[shell->i].fd_in != -1)
		close(shell->pipes[shell->i].fd_in);
	if (fd_file_exist(shell->str[shell->i], shell->j, 1))
		return (1);
	str = ft_find_file_name(shell->str[shell->i] + shell->j + 1, shell, 0);
	if (!str)
		return (1);
	shell->pipes[shell->i].fd_in = open(str, O_RDONLY, 0777);
	if (shell->pipes[shell->i].fd_in < 0)
	{
		printf("No such file or directory\n");
		return (1);
	}
	str1 = ft_substr(shell->str[shell->i], 0, shell->j);
	str2 = ft_strdup(shell->str[shell->i] + shell->n + 1);
	free(shell->str[shell->i]);
	shell->str[shell->i] = ft_strjoin(str1, str2);
	free(str);
	free(str1);
	free(str2);
	return (0);
}

int	fd_redirect_input_2(t_shell *shell)
{
	char	*str;
	char	*str1;
	char	*str2;
	char	*str3;
	int		j;

	if (shell->pipes[shell->i].fd_in != -1)
		close(shell->pipes[shell->i].fd_in);
	if (fd_file_exist(shell->str[shell->i], shell->j, 2))
		return (1);
	str = ft_find_file_name(shell->str[shell->i] + shell->j + 2, shell, 0);
	if (!str)
		return (1);
	j = ft_strlen(str);
	read_for_redirect(shell, str, j, 1);
	str1 = ft_substr(shell->str[shell->i], 0, shell->j);
	str2 = ft_strdup(shell->str[shell->i] + shell->n + 2);
	str3 = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	free(shell->str[shell->i]);
	shell->str[shell->i] = str3;
	return (0);
}
