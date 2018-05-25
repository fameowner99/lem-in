/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:17:16 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/25 17:39:43 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		lem_in()
{
	t_union	un;

	un.room = NULL;
	get_input(&un);
	if (un.flag.start && un.flag.end && un.flag.links && un.flag.ants)
	{
		algorithm(&un);
		while(1)
		{
		}
	
		un.ant = (t_ants *)malloc((sizeof(t_ants) + 1) * un.num_ants);
		if (un.all)
		{
			print_container(un.container);
			set_length_way(&un);
			set_ants(&un);
			while (check_finish(un))
				set_link_ant(&un);
		}
	}
	if (!un.all)
		{
			ft_printf(RED"ERROR\n"RESET);	
			return ;
		}
	clear_container(un.container);
}
