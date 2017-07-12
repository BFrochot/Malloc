/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:03:13 by bfrochot          #+#    #+#             */
/*   Updated: 2017/06/09 17:03:02 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		verif_ptr(void *ptr)
{
	t_link *node;

	node = g_truc->tiny;
	while (node->next)
	{
		if (ptr == node->next + 1)
			return (1);
		node = node->next;
	}
	node = g_truc->small;
	while (node->next)
	{
		if (ptr == node->next + 1)
			return (1);
		node = node->next;
	}
	node = g_truc->large;
	while (node->next)
	{
		if (ptr == node->next + 1)
			return (1);
		node = node->next;
	}
	return (0);
}

void	*realloc(void *ptr, size_t size)
{
	void	*ptr2;
	int		i;

	if (!size || !ptr)
		return (NULL);
	if (verif_ptr(ptr) == 0)
		return (NULL);
	ptr2 = malloc(size);
	if (ptr2 == NULL)
		return (NULL);
	i = -1;
	while ((size_t)i < size)
		((char *)ptr2)[i] = ((char *)ptr)[i];
	free(ptr);
	return (ptr2);
}
