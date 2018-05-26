/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_links_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:31:37 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/26 16:06:11 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_links		*links_list_new(t_rooms *room)
{
	t_links	*new;

	new = (t_links *)malloc(sizeof(t_links));
	new->room = room;
	new->next = NULL;
	return (new);
}

void		links_list_push_back(t_links *head, t_rooms *room)
{
	t_links	*new;
	t_links	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	new = links_list_new(room);
	tmp->next = new;
}

t_ways		*ways_list_new(t_rooms *room)
{
	t_ways	*new;

	new = (t_ways *)malloc(sizeof(t_ways));
	new->room = room;
	new->empty = 1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		ways_list_push_back(t_ways *head, t_rooms *room)
{
	t_ways	*new;
	t_ways	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	new = ways_list_new(room);
	tmp->next = new;
	new->prev = tmp;
}

t_ways		*ways_clear_last_node(t_ways *head)
{
	t_ways	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	free(tmp);
	if (tmp->prev)
		tmp->prev->next = NULL;
	else
		return (NULL);
	return (head);
}
