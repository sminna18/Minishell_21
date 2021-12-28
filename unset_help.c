/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:51:19 by kdakota           #+#    #+#             */
/*   Updated: 2021/12/26 20:51:30 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_arg_unset(char *str)
{
	int	i;

	i = 1;
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	unset_help1(t_com *com, int i)
{
	ft_putstr_fd("minishell: unset: `", 2);
	ft_putstr_fd(com->flags[i], 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}
