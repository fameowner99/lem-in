/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:23:16 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/20 18:26:46 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			is_comment(char *str)
{
	if (str[0] == '#')
	{
		if (!ft_strcmp(str, "##start") ||
				!ft_strcmp(str, "##end"))
			return (0);
		return (1);	
	}
	return (0);
}

static int		room(t_union *un, char *str)
{
	char		**arr;
	t_rooms		*room;

	arr = ft_strsplit(str, ' ');
	room = un->room;
	while (room)
	{
		if (!ft_strcmp(room->name, arr[0]) || (ft_atoi(arr[1]) == room->position.x && ft_atoi(arr[2]) == room->position.y))
			return (0);
		room = room->next;
	}
	if (!un->room)
		un->room = rooms_list_new(un, arr[0],ft_atoi(arr[1]), ft_atoi(arr[2]));
	else
		rooms_list_push_back(un, arr[0],ft_atoi(arr[1]), ft_atoi(arr[2]));
	ft_free_2d((void **)arr);
	return (1);
}

int			check_input(t_union *un, char *str)
{
	if (is_number(str) && !un->flag.ants)
	{	
		if (un->flag.start || un->flag.end || un->flag.links)
			return (0);
		un->flag.ants = 1;
		if (ft_atoi(str) == 0)
			return (0);
		un->num_ants = ft_atoi(str);
		return (1);
	}
	else if (un->flag.ants && is_start_end(str, un))
	{
		return (1);
	}
	else if (un->flag.ants && !un->flag.links && is_room(str))
	{
		return (room(un, str));
				
	}
	else if (un->flag.ants && un->flag.start == -1 && un->flag.end == -1 && is_link(un, str))
{
	un->flag.links = 1;
		return (1);
}
	else if (is_comment(str)) 
		return (1);
	return (0);
}

int			get_input(t_union *un)
{
	char	*str;
	un->container = NULL;

	set_flag(un);
	while (get_next_line(0, &str) > 0 )
	{
		if (!ft_strcmp(str, ""))
			{
				free(str);
				break ;
			}
		if (!check_input(un, str))
		{
			ft_printf("ERROR\n");
			break ;	
		}
		if (!un->container)
			un->container = container_new(str);
		else
			container_push_back(un->container, str);
		free(str);
	}
	ft_printf(RED"OKi\n"RESET);	
	if (un->flag.start && un->flag.end && un->flag.ants && un->flag.links)
		return (1);
	return (0);
}
