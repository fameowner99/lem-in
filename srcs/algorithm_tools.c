/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:29:06 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/23 17:25:08 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	set_lvl(t_union *un)
{
	t_rooms	*tmp;

	tmp = un->room;
	while (tmp)
	{
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
