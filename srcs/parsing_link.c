/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 17:47:45 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/19 19:17:42 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	check_if_exist(t_links *link, t_rooms *room)
{
	t_links	*tmp;

	tmp = link;
	while (tmp)
	{
		if (!ft_strcmp(tmp->room->name, room->name))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	connect_rooms(t_union *un, char *r1, char *r2)
{
	t_rooms *room;
	t_rooms *room1;
	t_rooms	*room2;

	room = un->room;
		while (room)
	{
		if (!ft_strcmp(room->name, r1))
			room1 = room;
		if (!ft_strcmp(room->name, r2))
			room2 = room;
		room = room->next;
	}
	if (!room1->link)
		room1->link = links_list_new(room2);
	else
		{
			if (check_if_exist(room1->link, room2))
				links_list_push_back(room1->link, room2);
		}
	if (!room2->link)
		room2->link = links_list_new(room1);
	else
		{
			if (check_if_exist(room2->link, room1))
				links_list_push_back(room2->link, room1);
		}
}

static int split(t_union *un, char *str)
{
	char	**arr;
	int		count;
	t_rooms	*room;

	count = 0;
	room = un->room;
	arr = ft_strsplit(str, '-');
	if (!ft_strcmp(arr[0],arr[1]))
		return (0);
	while (room)
	{
		if (!ft_strcmp(room->name, arr[0]))
			++count;
		if (!ft_strcmp(room->name, arr[1]))
			++count;
		room = room->next;
	}

	if (count != 2)
	{
		ft_free_2d((void **)arr);
		return (0);
	}
	connect_rooms(un, arr[0], arr[1]);
	ft_free_2d((void **)arr);
	return (1);
}

int		is_link(t_union *un, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '-')
			++count;
		++i;
	}
	if (count == 1)
		return (split(un, str));
	return (0);
}
