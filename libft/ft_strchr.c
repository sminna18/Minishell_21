/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:55:30 by sminna            #+#    #+#             */
/*   Updated: 2021/10/10 18:33:01 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	r;
	int	ccpy;

	i = 0;
	r = 0;
	ccpy = (char) c;
	while (s[r])
		r++;
	while (i <= r)
	{
		if (s[i] == ccpy)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
