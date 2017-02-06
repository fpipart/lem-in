/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:44:07 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/06 14:58:45 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	move_one_ant(t_lem *tmp, int path, t_store *store)
{
	if (!tmp->next || tmp->next->busy != path)
	{
		print_ant_position(tmp->ant, store->end);
		ft_bzero(tmp->ant, 11);
		store->ants_end++;
	}
	else if (!ft_isdigit(*(tmp->next->ant)))
	{
		print_ant_position(tmp->ant, tmp->next->room);
		ft_strcpy(tmp->next->ant, tmp->ant);
		ft_bzero(tmp->ant, 11);
	}
	return (0);
}

static int	move_ant_one_path(t_lem *new_map, int path, t_store *store)
{
	t_lem *tmp;
	t_lem *tmp_path;

	tmp_path = new_map;
	print_room(new_map);
	ft_putendl("159------------");
	ft_printf("path = %d\n", path);
	while (tmp_path && tmp_path->busy != path)
		tmp_path = tmp_path->next;
//	if (!ft_isdigit(*(tmp_path->ant)) || ft_isdigit(*(tmp_path->next->ant)))
//		while (tmp_path->next && (tmp_path->busy != path ||
//					!ft_isdigit(*(tmp_path->next->ant))))
//			tmp_path = tmp_path->next;
	tmp = tmp_path;
	if (!tmp->next)
		return (0);
	ft_putendl("159");
	while (tmp && tmp->busy == path)
	{
		tmp = tmp_path;
		if (!ft_isdigit(*(tmp->ant)))
			break ;
		while (tmp->next && tmp->next->busy == path
				&& ft_isdigit(*(tmp->next->ant)))
			tmp = tmp->next;
		move_one_ant(tmp, path, store);
	}
	return (0);
}

static int	move_ant_inside(t_lem *new_map, int path_nbr_max, t_store *store)
{
	t_lem	*tmp;
	int		path;

	path = 1;
	tmp = new_map;
	ft_putendl("159------------");
	while (path <= path_nbr_max)
	{
		move_ant_one_path(new_map, path, store);
		path++;
	}
	return (0);
}

int			fill_result(t_lem *new_map, t_store *store, int *size_paths)
{
	int	path_nbr_max;
//	int end_nbr;

	path_nbr_max = 0;
	store->ants_tot = store->ants;
	store->ants_strt = store->ants;
	store->ants_end = 0;
	store->ants = 1;
	print_room(new_map);
	while (*(size_paths + (path_nbr_max)) != -1)
		path_nbr_max++;
	path_nbr_max = 1;
	while (store->ants_strt != 0)
	{
		ft_putendl("Start");
		move_ant_inside(new_map, path_nbr_max, store);
		ft_putendl("MID");
		move_ants(new_map, store, size_paths, path_nbr_max);
		ft_putendl("End");
		ft_putchar('\n');
	}
//	while (store->ants_end != store->ants_tot)
//	{
//		end_nbr = move_ant_inside_end(&new_map, path_nbr_max, store);
//		ft_putchar('\n');
//		print_resolution(new_map, end_nbr);
//	}
	return (0);
}
