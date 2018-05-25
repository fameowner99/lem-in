/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_rooms_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:02:03 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/25 15:04:08 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_rooms		*rooms_list_new(t_union *un, char *name, int x, int y)
{
	t_rooms	*new;

	new = (t_rooms *)malloc(sizeof(t_rooms));
	new->name = (char *)ft_memalloc(ft_strlen(name) + 1);
	new->name = ft_strcpy(new->name, name);
	new->next = NULL;
	new->link = NULL;
	new->position.x = x;
	new->position.y = y;
	new->lvl = MAX_INT;
	new->start = 0;
	new->end = 0;
	new->closed = 0;
	if (un->flag.start == 1)
	{
		un->flag.start = -1;
		new->start = 1;
	}
	else if (un->flag.end == 1)
	{
		un->flag.end = -1;
		new->end = 1;
	}
	return (new);
}

void		rooms_list_push_back(t_union *un, char *name, int x, int y)
{
	t_rooms	*new;
	t_rooms	*tmp;

	tmp = un->room;
	while (tmp->next)
		tmp = tmp->next;
	new = rooms_list_new(un,name, x, y);
	tmp->next = new;
}

t_all_ways		*all_ways_list_new(t_ways *way)
{
	t_all_ways	*new;

	new = (t_all_ways*)malloc(sizeof(t_all_ways));
	new->way = way;
	new->len = 0;
	new->next = NULL;
	return (new);
}

void			all_ways_list_push_back(t_all_ways *head, t_ways *way)
{
	t_all_ways	*tmp;
	t_all_ways	*new;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	new = all_ways_list_new(way);
	tmp->next = new;
}
