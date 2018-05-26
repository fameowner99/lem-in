/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 12:11:23 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/26 16:05:13 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_all_ways		*find_the_shortest_path(t_union *un)
{
	int			min;
	t_all_ways	*all;
	t_all_ways	*way;

	min = MAX_INT;
	all = un->all;
	while (all)
	{
		if (min > all->len)
		{
			min = all->len;
			way = all;
		}
		all = all->next;
	}
	return (way);
}

void			set_ants(t_union *un)
{
	t_ants		*ant;
	int			i;

	ant = un->ant;
	i = 0;
	while (i < un->num_ants)
	{
		ant[i].n = i + 1;
		ant[i].all = find_the_shortest_path(un);
		ant[i].curr_way = ant[i].all->way;
		++ant[i].all->len;
		++i;
	}
}

int				check_finish(t_union un)
{
	int			i;

	i = 0;
	while (i < un.num_ants)
	{
		if (un.ant[i].curr_way)
			return (1);
		++i;
	}
	return (0);
}

void			set_link_ant(t_union *un)
{
	int			i;

	i = 0;
	while (i < un->num_ants)
	{
		if (un->ant[i].curr_way)
		{
			if (!un->ant[i].curr_way->next || un->ant[i].curr_way->next->empty)
			{
				un->ant[i].curr_way->empty = 1;
				un->ant[i].curr_way = un->ant[i].curr_way->next;
				if (un->ant[i].curr_way)
				{
					ft_printf(RED"L%i-%s "RESET, un->ant[i].n,
								un->ant[i].curr_way->room->name);
					un->ant[i].curr_way->empty = 0;
				}
			}
		}
		++i;
	}
	if (check_finish(*un))
		ft_printf("\n");
}
