/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:11:53 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/26 16:08:34 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void				set_length_way(t_union *un)
{
	t_ways			*way;
	t_all_ways		*all;
	int				counter;

	all = un->all;
	while (all)
	{
		counter = 0;
		way = all->way;
		while (way)
		{
			++counter;
			way = way->next;
		}
		all->len = counter - 1;
		all = all->next;
	}
}

void				clear_lst_ways(t_ways *way)
{
	t_ways			*tmp;

	tmp = way;
	while (tmp)
	{
		tmp = tmp->next;
		way->next = NULL;
		free(way);
		way = tmp;
	}
}

void				clear_rooms_links(t_union *un)
{
	t_rooms			*room;
	t_links			*link;

	room = un->room;
	while (room)
	{
		link = room->link;
		while (link)
		{
			link = link->next;
			free(un->room->link);
			un->room->link = link;
		}
		room = room->next;
		free(un->room);
		free(un->room->name);
		un->room = room;
	}
}

void				clear_all_ways(t_union *un)
{
	t_all_ways		*all;
	t_ways			*way;
	t_ways			*tmp;

	all = un->all;
	while (all)
	{
		way = all->way;
		while (way)
		{
			tmp = way->next;
			free(way);
			way = tmp;
		}
		all = all->next;
		free(un->all);
		un->all = all;
	}
}
