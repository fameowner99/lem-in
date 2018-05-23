/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:17:16 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/23 12:32:04 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		lem_in()
{
	t_union	un;
	t_ways	way;

	un.room = NULL;
	way.room = NULL;
	if (get_input(&un))
	{
		algorithm(&un);	
	}
}
