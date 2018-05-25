/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:11:53 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/25 17:51:13 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void				set_length_way(t_union *un)
{
	t_ways		*way;
	t_all_ways 	*all;
	int			counter;

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
void			clear_lst_ways(t_ways *way)
{
	t_ways		*tmp;

	tmp = way;
	while (tmp)
	{
		tmp = tmp->next;
		way->next = NULL;
		free(way);
		way = tmp;
	}
}
