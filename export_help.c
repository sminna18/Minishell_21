/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:48:53 by kdakota           #+#    #+#             */
/*   Updated: 2021/12/26 20:49:31 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export_error(char *str)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

int	parsing_export(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (!ft_isalpha(str[i]) && str[i] != '_')
	{
		print_export_error(str);
		return (0);
	}
	if (str[i] == '_' && (str[i + 1] == '\0' || str[i + 1] == '='))
		return (0);
	i++;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
		{
			print_export_error(str);
			return (0);
		}
		i++;
	}
	return (1);
}

char	*arg_tipo_unset(char *arg)
{
	char	*arg_new;
	int		i;

	i = 0;
	arg_new = malloc(1000);
	while (arg[i] && arg[i] != '=')
	{
		arg_new[i] = arg[i];
		i++;
	}
	arg_new[i] = '\0';
	return (arg_new);
}

int	tipo_unset_h_c2(char *arg, char *help)
{
	if (ft_strncmp(help, arg, ft_strlen_sym(help, '=')) == 0
		&& (arg[ft_strlen_sym(help, '=')] == '\0'
			|| arg[ft_strlen_sym(help, '=')] == '='))
	{
		return (1);
	}
	return (0);
}

int	tipo_unset_h_c1(char *arg, t_list **evl, char *help, t_list *l1)
{
	if (l1 == *evl
		&& ft_strncmp(help, arg, ft_strlen_sym(help, '=')) == 0
		&& (arg[ft_strlen_sym(help, '=')] == '\0'
			|| arg[ft_strlen_sym(help, '=')] == '='))
	{
		return (1);
	}
	return (0);
}
