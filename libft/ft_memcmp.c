/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:55:51 by sminna            #+#    #+#             */
/*   Updated: 2021/10/10 18:32:19 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char		*sl;
	char		*ss;
	size_t		i;

	i = 0;
	sl = (char *) s1;
	ss = (char *) s2;
	while (i < n)
	{
		if (sl[i] != ss[i])
			return ((unsigned char)sl[i] - (unsigned char)ss[i]);
		i++;
	}
	return (0);
}
