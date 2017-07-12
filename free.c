/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:03:08 by bfrochot          #+#    #+#             */
/*   Updated: 2017/06/09 16:59:08 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		check_node(void *ptr, t_link *node)
{
	while (node->next)
	{
		if (ptr == node->next + 1)
		{
			if ((char *)node->next->end - (char *)node->next <= TNY)
				g_truc->tinycurr -= (char *)node->next->end
				- (char *)(node->next + 1);
			else
				g_truc->smallcurr -= (char *)node->next->end
				- (char *)(node->next + 1);
			node->next = node->next->next;
			return (1);
		}
		node = node->next;
	}
	return (0);
}

void	free(void *ptr)
{
	t_link *node;
	t_link *nxt;

	if (!ptr)
		return ;
	if (check_node(ptr, g_truc->tiny) == 1)
		return ;
	if (check_node(ptr, g_truc->small) == 1)
		return ;
	node = g_truc->large;
	while (node->next)
	{
		nxt = node->next->next;
		if (node->next + 1 == ptr)
		{
			munmap(node->next, (char *)node->next->end - (char *)node->next);
			node->next = nxt;
			break ;
		}
		node = node->next;
	}
	return ;
}
