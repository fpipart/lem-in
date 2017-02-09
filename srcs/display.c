/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:44:07 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/09 10:40:50 by fpipart          ###   ########.fr       */
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
	else if (tmp->next && !ft_isdigit(*(tmp->next->ant)))
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
	while (tmp_path && tmp_path->busy != path)
		tmp_path = tmp_path->next;
	if (tmp_path && (!ft_isdigit(*(tmp_path->ant)) ||
				(tmp_path->next && ft_isdigit(*(tmp_path->next->ant)))))
		while (tmp_path->next && (tmp_path->busy != path ||
					!ft_isdigit(*(tmp_path->next->ant))))
			tmp_path = tmp_path->next;
	tmp = tmp_path;
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
	while (path <= path_nbr_max)
	{
		move_ant_one_path(new_map, path, store);
		path++;
	}
	return (0);
}

static void	init_store_b4fill(t_store *store)
{
	store->ants_tot = store->ants;
	store->ants_strt = store->ants;
	store->ants_end = 0;
	store->ants = 1;
}

int			fill_result(t_lem *new_map, t_store *store, int *size_paths)
{
	int	path_nbr_max;
	int end_nbr;

	path_nbr_max = 0;
	init_store_b4fill(store);
	while (*(size_paths + (path_nbr_max)) != -1)
		path_nbr_max++;
	while (store->ants_strt != 0)
	{
		if (store->start_end == 1)
			move_ant_s_to_e(store);
		if (new_map)
		{
			move_ant_inside(new_map, path_nbr_max, store);
			move_ants(new_map, store, size_paths, path_nbr_max);
		}
		ft_putchar('\n');
	}
	while (store->ants_end != store->ants_tot)
	{
		end_nbr = move_ant_inside_end(&new_map, path_nbr_max, store);
		ft_putchar('\n');
	}
	return (0);
}
