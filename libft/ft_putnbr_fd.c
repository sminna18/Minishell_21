/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:55:35 by sminna            #+#    #+#             */
/*   Updated: 2021/10/11 11:44:02 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		min;
	char	x[12];
	int		i;

	i = 0;
	min = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		min = -1;
	}
	while (n > 9 || n < -9)
	{
		x[i] = (n % 10 * min) + '0';
		n = n / 10;
		i++;
	}
	x[i] = n * min + '0';
	while (i >= 0)
	{
		ft_putchar_fd(x[i], fd);
		i--;
	}
}
