/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:05:04 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/24 16:59:52 by fpipart          ###   ########.fr       */
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

void					del_lst(t_lem **lem, t_lem **cmd);

#endif
