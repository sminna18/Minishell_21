/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:55:45 by sminna            #+#    #+#             */
/*   Updated: 2021/10/10 18:32:28 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dstcpy;
	char	*srccpy;

	i = 0;
	dstcpy = (char *) dst;
	srccpy = (char *) src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
	{
		while (len-- > i)
		{
			dstcpy[len] = srccpy[len];
		}
	}
	else
	{
		while (len > i)
		{
			dstcpy[i] = srccpy[i];
			i++;
		}
	}
	return (dst);
}
