/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:56:17 by sminna            #+#    #+#             */
/*   Updated: 2021/12/11 15:59:23 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_bzero(void *b, size_t len)
{
	size_t	i;
	char	*d;

	i = 0;
	d = (char *) b;
	while (i < len)
	{
		d[i] = 0;
		i++;
	}
}
