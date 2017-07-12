/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:06:47 by bfrochot          #+#    #+#             */
/*   Updated: 2017/06/09 17:09:21 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>

# define TNY 8 * getpagesize()
# define SML 32 * getpagesize()
# define TINY_MAX (size_t)TNY * 100
# define SML_MAX (size_t)SML * 100
# define PRT PROT_READ | PROT_WRITE
# define MAP MAP_ANON | MAP_PRIVATE

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				init();
void				show_alloc_mem();
void				ft_putchar(char u);
void				ft_putstr(char *str);
void				ft_putnbr(int i);

typedef struct		s_link
{
	struct s_link	*end;
	struct s_link	*next;
}					t_link;

typedef struct		s_struc
{
	t_link			*tiny;
	size_t			tinycurr;
	t_link			*small;
	size_t			smallcurr;
	t_link			*large;
}					t_struc;

extern t_struc		*g_truc;

#endif
