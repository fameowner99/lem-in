/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:15:28 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/24 19:50:24 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
 
 
 
int         find_min_lvl(t_rooms *room)
{
    int     min;
    t_links *link;
 
    min = MAX_INT;
    link = room->link;
    while (link)
    {
        if (link->room->closed == 0 && link->room->lvl < min)
            min = link->room->lvl;
        link = link->next;
    }
    return (min);
}
 
void        set_graph_level(t_rooms *start, t_union *un)
{
    t_links *tmp;
 
    tmp = start->link;
    if (start->lvl != 0)
        start->lvl = find_min_lvl(start) + 1;
    while (tmp)
    {   
        if (!start->closed && start->lvl < tmp->room->lvl)
        ways_list_push_back(QUEUE, tmp->room);
        tmp = tmp->next;
    }
    QUEUE = QUEUE->next;
    while (QUEUE)
        set_graph_level(QUEUE->room, un);
}
 
t_ways      *find_way(t_rooms *cur_room)
{
    t_ways  *way;
    t_rooms *room;
    int     n;
    t_links *link;
 
    room = find_end_room(cur_room);
    way = ways_list_new(room);
	link = room->link;
    while(link)
    {
        n = find_min_lvl(room);
        if (!link->room->closed && link->room->lvl == n)
        {	
			room = link->room;
			link = room->link;
			if (!room->start && !room->end)
            	room->closed = 1;
             way = ways_list_push_front(way, room);
            if (room->start)
                return  (way);
        }
        else
            link = link->next;
    }
    return (NULL);
}
 
void    algorithm(t_union *un)
{
	t_ways	*q_tmp;
	t_ways *way;

	if (check_link_start_end(un))
	{
		way =  ways_list_new(find_start_room(un->room));
		ways_list_push_back(way, find_end_room(un->room));
		un->all = all_ways_list_new(way);
	}
	else
	{
    set_lvl(un);
    QUEUE = ways_list_new(find_start_room(un->room));
	q_tmp = QUEUE;
    set_graph_level(find_start_room(un->room), un);
	way = find_way(un->room);
	if (way)
		un->all = all_ways_list_new(way);
	set_lvl(un);
	 QUEUE = ways_list_new(find_start_room(un->room));
    set_graph_level(find_start_room(un->room), un);
    while ((way = find_way(un->room)))
	{	
		set_lvl(un);
	 QUEUE = ways_list_new(find_start_room(un->room));
    set_graph_level(find_start_room(un->room), un);
		all_ways_list_push_back(un->all, way);	
	}
	}
	int i;
	i = 1;
	while (un->all)
	{
		ft_printf(RED"%i\n"RESET, i);
		while (un->all->way)
		{
			ft_printf(GREEN"%s\n"RESET, un->all->way->room->name);
			un->all->way = un->all->way->next;
		}
		un->all = un->all->next;
		++i;
	}
 }
