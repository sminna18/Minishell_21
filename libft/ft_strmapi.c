/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:40:12 by sminna            #+#    #+#             */
/*   Updated: 2021/10/09 18:00:28 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*x;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	x = malloc (len + 1);
	if (!x)
		return (0);
	while (i < len)
	{
		x[i] = f(i, s[i]);
		i++;
	}
	x[i] = 0;
	return (x);
}
