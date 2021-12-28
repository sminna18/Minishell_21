/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:55:20 by sminna            #+#    #+#             */
/*   Updated: 2021/10/10 18:33:16 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	e;

	i = 0;
	e = 0;
	while (src[e])
		e++;
	if (!size)
		return (e);
	size--;
	while (src[i] && size > i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (e);
}
