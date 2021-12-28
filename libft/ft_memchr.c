/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:55:55 by sminna            #+#    #+#             */
/*   Updated: 2021/10/10 18:32:14 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*scpy;
	char	ccpy;

	i = 0;
	scpy = (char *) s;
	ccpy = (char) c;
	while (n > i)
	{
		if (scpy[i] == ccpy)
			return ((char *)(scpy + i));
		i++;
	}
	return (NULL);
}
