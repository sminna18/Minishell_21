/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:55:12 by sminna            #+#    #+#             */
/*   Updated: 2021/10/10 18:33:34 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	z;

	i = 0;
	z = 0;
	if (needle[0] == 0)
		return ((char *)(haystack));
	while (needle[z])
		z++;
	while (haystack[i] && i < len)
	{
		l = 0;
		while (haystack[i + l] == needle[l] && haystack[i + l] && i + l < len)
		{
			l++;
			if (l == z)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
