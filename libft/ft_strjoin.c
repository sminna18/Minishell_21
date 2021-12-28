/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:55:25 by sminna            #+#    #+#             */
/*   Updated: 2021/12/27 13:45:24 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i[3];
	char	*x;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (!s1 || !s2)
		return (0);
	i[1] = ft_strlen(s1);
	i[2] = ft_strlen(s2);
	x = malloc(i[1] + i[2] + 2);
	if (x == 0)
		return (0);
	while (i[0] <= i[1])
	{
		x[i[0]] = s1[i[0]];
		i[0]++;
	}
	i[0] = -1;
	while (++i[0] <= i[2])
		x[i[1] + i[0]] = s2[i[0]];
	x[i[1] + i[0]] = 0;
	return (x);
}
