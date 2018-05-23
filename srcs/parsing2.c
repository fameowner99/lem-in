/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:49:51 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/20 12:54:15 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			is_number(char	*str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		++i;
	}
	if (ft_atoi_ui(str) > MAX_INT)
		return (0);
	return (1);
}

int			is_room(char *str)
{
	int		i;
	int		space;
	int		wrd;
	char	**arr;

	i = 0;
	space = 0;
	wrd = ft_count_words(str, ' ');
	while (str[i])
	{
		if (str[i] == ' ')
			++space;
		++i;
	}
	if (wrd == 3 && space == 2)
	{
		arr = ft_strsplit(str, ' ');	
		if (arr[1] && arr[2] && is_number(arr[1]) && is_number(arr[2]) &&
			is_correct_name(str))
		{
			ft_free_2d((void **)arr);
			return (1);
		}
	}
	return (0);
}

int			is_start_end(char *str, t_union *un)
{
	if (!ft_strcmp(str, "##start") && un->flag.end != 1 && un->flag.start == 0)
	{
		un->flag.start = 1;
		return (1);
	}
	else if (!ft_strcmp(str, "##end") && un->flag.start != 1 && un->flag.end == 0 )
	{
		un->flag.end = 1;
		return (1);
	}
	return (0);
		
}

int		is_correct_name(char *str)
{
	int	i;

	i = 0;
	if (str[0] == 'L' || str[0] == '#')
		return (0);
	while (str[i])
	{
		if (str[i] == '-')
			return (0);
		++i;
	}
	return (1);
}
