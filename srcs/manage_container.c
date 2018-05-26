/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_container.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:40:58 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/26 16:05:36 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_container			*container_new(char *str)
{
	t_container		*res;

	if (!(res = (t_container *)malloc(sizeof(t_container))))
		return (NULL);
	if (!(res->str = (char *)ft_memalloc(ft_strlen(str) + 1)))
		return (NULL);
	res->str = ft_strcpy(res->str, str);
	res->next = NULL;
	return (res);
}

void				container_push_back(t_container *head, char *str)
{
	t_container		*tmp;
	t_container		*new;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	new = container_new(str);
	tmp->next = new;
}

void				clear_container(t_union *un)
{
	t_container		*tmp;

	while (un->container)
	{
		tmp = un->container->next;
		free(un->container->str);
		free(un->container);
		un->container = tmp;
	}
}

void				print_container(t_container *head)
{
	t_container		*tmp;

	tmp = head;
	while (tmp)
	{
		ft_printf(GREEN"%s\n"RESET, tmp->str);
		tmp = tmp->next;
	}
}
