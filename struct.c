/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:05:47 by bfrochot          #+#    #+#             */
/*   Updated: 2017/06/09 17:01:38 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_struc *g_truc = NULL;

void	init(void)
{
	if (g_truc == NULL)
	{
		g_truc = mmap(NULL, sizeof(t_struc)
		+ sizeof(t_link) * 201 + TNY * 100 + SML * 100, PRT, MAP, -1, 0);
		g_truc->large = (t_link *)(g_truc + 1);
		g_truc->tiny = g_truc->large + 1;
		g_truc->tiny->next = NULL;
		g_truc->tiny->end = g_truc->tiny + 1;
		g_truc->small = (t_link *)((char *)g_truc
		+ sizeof(t_link) * 101 + TNY * 100);
		g_truc->small->next = NULL;
		g_truc->small->end = g_truc->small + 1;
		g_truc->tinycurr = 0;
		g_truc->smallcurr = 0;
		g_truc->large->next = NULL;
	}
}
