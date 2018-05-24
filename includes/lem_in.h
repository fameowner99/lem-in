/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:35:32 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/24 19:42:07 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# define QUEUE un->q

# define MAX_INT 2147483646

# include "../libft/libft.h"

typedef struct s_links	t_links;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_flag
{
	int					ants;
	int					start;
	int					end;
	int					links;
}						t_flag;

typedef struct			s_rooms
{
	char				*name;
	t_point				position;
	int					start;
	int					end;
	int					closed;
	int					lvl;
	t_links				*link;
	struct s_rooms		*next;
}						t_rooms;

struct					s_links
{
	t_rooms				*room;
	struct s_links		*next;
}							;

typedef struct			s_container
{
	char				*str;
	struct s_container	*next;
}						t_container;

typedef struct			s_ways
{
	t_rooms				*room;
	struct s_ways		*prev;
	struct s_ways		*next;
}						t_ways;

typedef struct			s_all_ways
{
	t_ways				*way;
	struct s_all_ways	*next;
}						t_all_ways;

typedef struct			s_union
{
	int					num_ants;
	t_flag				flag;
	int					found;
	t_container			*container;
	t_rooms				*room;
	t_ways				*q;
	t_all_ways			*all;
}						t_union;

void					lem_in();
int						get_input(t_union *un);
t_container				*container_new(char *str);
void					container_push_back(t_container *head, char *str);
void					clear_container(t_container *head);
void					set_flag(t_union *un);
t_rooms					*rooms_list_new(t_union *un, char *name, int x, int y);
t_ways					*ways_list_new(t_rooms *room);
void					ways_list_push_back(t_ways *head, t_rooms *room);
t_ways					*ways_clear_last_node(t_ways *head);
void					rooms_list_push_back(t_union *un, char *name, int x, int y);
t_links					*links_list_new(t_rooms *room);
void					links_list_push_back(t_links *head, t_rooms *room);
int						is_link(t_union *un, char *str);
int						is_room(char *str);
int						is_start_end(char *str, t_union *un);
int						is_number(char	*str);
int						is_correct_name(char *str);
t_rooms					*find_start_room(t_rooms *room);
void					set_graph_level(t_rooms	*start, t_union *un);
void					set_lvl(t_union *un);
void					algorithm(t_union *un);
t_rooms					*find_end_room(t_rooms *room);
t_ways					*ways_list_push_front(t_ways *head, t_rooms *room);
void					all_ways_list_push_back(t_all_ways *head, t_ways *way);
t_all_ways				*all_ways_list_new(t_ways *way);
int						check_link_start_end(t_union *un);


#endif
