/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:29:06 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/24 19:49:48 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	set_lvl(t_union *un)
{
	t_rooms	*tmp;

	tmp = un->room;
	while (tmp)
	{	
		tmp->lvl = MAX_INT;
		if (tmp->start)
			tmp->lvl = 0;
		tmp = tmp->next;
	}
}

t_rooms		*find_start_room(t_rooms *room)
{
	t_rooms	*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->start)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_rooms		*find_end_room(t_rooms *room)
{
	t_rooms	*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->end)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_ways		*ways_list_push_front(t_ways *head, t_rooms *room)
{
	t_ways	*new;

	new = ways_list_new(room);
	new->next = head;
	return (new);
}

int			check_link_start_end(t_union *un)
{
	t_rooms	*room;
	t_links	*link;

	room = find_start_room(un->room);
	link = room->link;
	while (link)
	{
		if (link->room->end)
			return (1);
		link = link->next;
	}
	return (0);
}
