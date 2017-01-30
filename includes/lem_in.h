/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:05:04 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/30 11:15:38 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/libft.h"
#include <stdlib.h>

typedef struct			s_lem
{
		char			*room;
		char			cmd[6];
		int				crd_x;
		int				crd_y;
		int				busy;
		int				len;
		struct s_list	*lst;
		struct s_lem	*next;
}						t_lem;

typedef struct			s_store
{
		int				ants;
		int				nbr_rm;
		int				tube;
		int				step;
		char			cmd[6];
		char			*start;
		char			*end;
}						t_store;

int						ft_atoi_checker(char *str, int *error);
/*
 **		utilities.c
 */
int						addelem(t_lem **old, t_lem *neww, t_store *store);
void					print_room(t_lem *room);
void					free_tab(char **tab, int word);
t_store					init_store(void);
/*
 **		utilities_tube.c
 */
int						add_connection(t_lem **lem, char **tab);
void					print_res(t_lem *lem);

void					del_lst(t_lem **lem);
/*
 **		algo.c
 */
int						resolve(t_lem *lem, t_store *store);
int						one_step(t_lem **lem, char *room, char *end, int step);
/*
 **		algo_shortest_paths.c
 */
int						select_room(t_lem **lem, char *end, int step);
int						set_busy(t_lem **lem, char *room, int end_index, int step);
void					restart_len(t_lem **lem);

#endif
