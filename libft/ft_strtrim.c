/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:55:07 by sminna            #+#    #+#             */
/*   Updated: 2021/10/11 17:17:33 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		min;
	int		max;
	char	*x;

	i = 0;
	min = 0;
	max = 0;
	if (!s1 || !set)
		return (0);
	max = ft_strlen (s1);
	max--;
	while (s1[min] && ft_strchr(set, s1[min]))
		min++;
	while (max > min && ft_strchr(set, s1[max]))
		max--;
	x = (char *)malloc(sizeof(char) * (max - min + 2));
	if (x == 0)
		return (0);
	while (max >= min)
		x[i++] = s1[min++];
	x[i] = '\0';
	return (x);
}
