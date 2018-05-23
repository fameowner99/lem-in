/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:15:28 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/23 18:45:17 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"



int			find_min_lvl(t_rooms *room)
{
	int		min;
	t_links	*link;

	min = MAX_INT;
	link = room->link;
	while (link)
	{
		if (link->room->lvl < min)
			min = link->room->lvl;
		link = link->next;
	}
	return (min);
}

void		set_graph_level(t_rooms	*start, t_union *un)
{
	t_links *tmp;

	tmp = start->link;
	if (start->lvl != 0)
		start->lvl = find_min_lvl(start) + 1;
	while (tmp)
	{	
		if (start->lvl < tmp->room->lvl)
		ways_list_push_back(QUEUE, tmp->room);
		tmp = tmp->next;
	}
	QUEUE = QUEUE->next;
	while (QUEUE)
		set_graph_level(QUEUE->room, un);
}

t_ways		*find_way(t_union *un)
{
	t_ways	*way;
	t_rooms	*room;
	int		n;
	t_links *link;

	room = find_end_room(un->room);
	way = ways_list_new(room);
/*	while (un->room)
	{
		ft_printf(RED"name: %s\n"RESET, un->room->name);
		while (un->room->link)
		{
			ft_printf(GREEN"%s\n"RESET, un->room->link->room->name);
			un->room->link = un->room->link->next;
		}
		un->room = un->room->next;
	}*/
	while (room->link)
	{
		ft_printf("%s\n", room->name);
		room = room->link->room;
		room->link = room->link->next;
	}
	return (way);
}

void	algorithm(t_union *un)
{
	set_lvl(un);
	QUEUE = ways_list_new(find_start_room(un->room));
	set_graph_level(find_start_room(un->room), un);
	t_ways *way;
	way = find_way(un);
	while (way)
	{
		ft_printf(RED"%s\n"RESET, way->room->name);
		way = way->next;
	}
	
}
