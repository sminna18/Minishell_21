/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:23:07 by sminna            #+#    #+#             */
/*   Updated: 2021/10/11 17:16:52 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_counter(int n, int i)
{
	while (n > 9 || n < -9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_translate(int i, int g, int n, char *x)
{
	int	min;

	min = 1;
	if (n < 0)
		min = -1;
	while (i >= g)
	{
		x[i] = (n % 10 * min) + '0';
		n = n / 10;
		i--;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	int		min;
	int		i;
	int		g;
	char	*x;

	min = 1;
	i = 0;
	g = 0;
	if (n < 0)
	{
		min = -1;
		g = 1;
		i++;
	}
	i = ft_counter(n, i);
	x = malloc (i + 2);
	if (x == 0)
		return (0);
	x[i + 1] = 0;
	x = ft_translate(i, g, n, x);
	if (min == -1)
		x[0] = '-';
	return (x);
}
