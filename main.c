/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:08:03 by bfrochot          #+#    #+#             */
/*   Updated: 2017/06/09 17:08:12 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		main(void)
{
	int		i;
	char	*str;

	show_alloc_mem();
	i = 1;
	while (i < 101)
	{
		str = malloc(10000 * i);
		if (str == NULL)
			ft_putstr("BITE\n");
		*str = 'a';
		realloc(str, 1000 * i * 2);
		++i;
	}
	show_alloc_mem();
}
