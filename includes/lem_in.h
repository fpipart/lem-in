/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:05:04 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/14 14:15:07 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <stdlib.h>


/* COLOR = "true" or "false" */
# define COLOR "false"

typedef struct			s_lem
{
	char				*room;
	char				ant[11];
	int					crd_x;
	int					crd_y;
	int					busy;
	int					len;
	struct s_list		*lst;
	struct s_lem		*next;
}						t_lem;

typedef struct			s_store
{
	int					ants;
	int					ants_tot;
	int					ants_strt;
	int					ants_end;
	int					nbr_rm;
	int					start_end;
	int					tube;
	int					step;
	char				cmd[6];
	char				*start;
	char				*end;
}						t_store;

/*
**		lemin2.c
*/

int						command(char *line, t_store *store);
void					store_cmd(t_store *store, char *cmd, char *room);
void					init_new_lem(char **tab, t_lem **neww, int *error);
int						handle_nbr(t_store *store, char *line, t_lem **lem);
/*
**		check_validity.c
*/
int						check_validity(t_store store, t_lem *lem);
int						check_path(t_store *store, t_lem *lem);
void					print_error(void);
/*
**		ft_atoi_checker.c
*/
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

void					del_lst(t_lem **lem);
/*
**		algo.c
*/
int						resolve(t_lem *lem, t_store *store, t_list *lst);
int						one_step(t_lem **lem, char *room, t_store *store,
		int step);
/*
**		algo_shortest_paths.c
*/
int						select_room(t_lem **lem, t_store *store, int step);
int						set_busy(t_lem **lem, char *room, int end_index,
		int step);
void					restart_len(t_lem **lem);
t_lem					*find_linked_rm(char *room, t_lem **lem);
/*
**		reshape_map.c
*/
int						reshape_map(t_lem *lem, t_lem **new_map,
		t_store *store, int path_nbr);
/*
**		manage_path.c
*/
int						nbr_path_max(t_lem *lem, t_store *store);
/*
**		nbr_path.c
*/
int						choose_paths(t_lem *lem, t_store *store,
		int path_nbr, int **tab);
/*
**		display.c
*/
int						fill_result(t_lem *new_map, t_store *store,
		int *size_paths);
/*
**		move_ant.c
*/
int						move_ants(t_lem *new_map, t_store *store,
		int *size_paths, int path_nbr_max);
int						move_ant_inside_end(t_lem **new_map,
		int path_nbr_max, t_store *store);
/*
**		display_resolution.c
*/
int						print_ant_position(char *ant, char *room);
void					print_map(t_list *lst);
/*
**		handle_ant_s_to_e.c
*/
int						move_ant_s_to_e(t_store *store);

#endif
