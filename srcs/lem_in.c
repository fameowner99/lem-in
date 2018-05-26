/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:17:16 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/26 16:01:39 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		lem_in(void)
{
	t_union	un;

	un.room = NULL;
	get_input(&un);
	if (un.flag.start && un.flag.end && un.flag.links && un.flag.ants)
	{
		algorithm(&un, NULL, NULL);
		if (un.all)
		{
			un.ant = (t_ants *)malloc((sizeof(t_ants) + 1) * un.num_ants);
			print_container(un.container);
			set_length_way(&un);
			set_ants(&un);
			while (check_finish(un))
				set_link_ant(&un);
			free(un.ant);
		}
	}
	if (!un.all)
		ft_printf(RED"ERROR\n"RESET);
	clear_rooms_links(&un);
	clear_all_ways(&un);
	clear_container(&un);
}
