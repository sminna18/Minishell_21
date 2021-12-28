/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:45:55 by sminna            #+#    #+#             */
/*   Updated: 2021/12/27 18:49:49 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tmp_changer(t_shell *shell)
{
	shell->tmp_split_p = 0;
	shell->tmp_split_on_off = 1;
}

void	double_free(char *str1, char *str2)
{
	free(str1);
	free(str2);
}
