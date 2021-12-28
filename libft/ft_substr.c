/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:55:04 by sminna            #+#    #+#             */
/*   Updated: 2021/12/07 15:04:51 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	ss;
	char	*x;

	if (!s)
		return (0);
	i = 0;
	l = 0;
	ss = ft_strlen(s);
	if (ss > start)
	{
		while (s[start + i] && i < len)
			i++;
	}
	x = malloc(i + 1);
	if (x == 0)
		return (0);
	while (l < i)
	{
		x[l] = s[start + l];
		l++;
	}
	x[l] = 0;
	return (x);
}
