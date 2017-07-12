/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:08:35 by bfrochot          #+#    #+#             */
/*   Updated: 2017/06/09 16:59:07 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ft_putchar(char u)
{
	write(1, &u, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putnbr(int i)
{
	if (i >= 0)
		i *= -1;
	else
		ft_putchar('-');
	if (i < -9)
		ft_putnbr(-(i / 10));
	ft_putchar(-(i % 10) + '0');
}
