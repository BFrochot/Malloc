/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:03:01 by bfrochot          #+#    #+#             */
/*   Updated: 2017/06/09 17:01:05 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*small_alloc(t_link *test, long size)
{
	t_link *node;
	t_link *old;

	node = test;
	while (test->next)
	{
		if ((char *)test->next - (char *)test->end >= size)
			break ;
		test = test->next;
	}
	old = test->next;
	test->next = test->end;
	test->next->end = (t_link *)((char *)test->next + size);
	test->next->next = old;
	return (test->next + 1);
}

void	*malloc(size_t size)
{
	t_link *node;

	if (!size)
		return (NULL);
	init();
	if ((long)size <= TNY)
	{
		if ((g_truc->tinycurr += size) > TINY_MAX)
			return (NULL);
		return (small_alloc(g_truc->tiny, size + sizeof(t_link)));
	}
	else if ((long)size <= SML)
	{
		if ((g_truc->smallcurr += size) > SML_MAX)
			return (NULL);
		return (small_alloc(g_truc->small, size + sizeof(t_link)));
	}
	node = g_truc->large;
	while (node->next)
		node = node->next;
	if (!(node->next = mmap(NULL, size + sizeof(t_link), PRT, MAP, -1, 0)))
		return (NULL);
	node->next->next = NULL;
	node->next->end = (t_link *)((char *)(node->next + 1) + size);
	return (node->next + 1);
}
