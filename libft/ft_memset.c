/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:55:43 by sminna            #+#    #+#             */
/*   Updated: 2021/10/10 18:32:33 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*d;
	char		x;

	i = 0;
	d = (char *) b;
	x = (char) c;
	while (i < len)
	{
		d[i] = x;
		i++;
	}
	return (b);
}
