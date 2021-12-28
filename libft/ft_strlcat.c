/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:55:23 by sminna            #+#    #+#             */
/*   Updated: 2021/10/10 13:57:44 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;

	s = 0;
	if (!dst)
		return (ft_strlen(dst));
	if (!src)
		return (ft_strlen(dst) + ft_strlen(src));
	d = ft_strlen(dst);
	while (src[s] && size > s + d + 1)
	{
		dst[d + s] = src[s];
		s++;
	}
	if (d + s < size)
		dst[d + s] = 0;
	s = ft_strlen(src);
	if (d > size)
		d = size;
	return (d + s);
}
