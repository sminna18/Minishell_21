/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:55:48 by sminna            #+#    #+#             */
/*   Updated: 2021/10/10 18:32:23 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dstcpy;
	char	*srccpy;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	dstcpy = (char *) dst;
	srccpy = (char *) src;
	while (n > i)
	{
		dstcpy[i] = srccpy [i];
		i++;
	}
	return (dst);
}
