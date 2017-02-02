/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:44:07 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/01 18:32:52 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	move_one_ant(t_lem *tmp, int path, t_store *store)
{
	if (!tmp->next || tmp->next->busy != path)
	{
		ft_bzero(tmp->ant, 11);
		store->ants_end++;
	}
	else if (!ft_isdigit(*(tmp->next->ant)))
	{
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
		ft_putendl("Coucou_______________________________________");
	while (tmp_path->busy != path)
		tmp_path = tmp_path->next;
	if (!ft_isdigit(*(tmp_path->ant)) || ft_isdigit(*(tmp_path->next->ant)))
	{
		while (tmp_path->next && (tmp_path->busy != path || !ft_isdigit(*(tmp_path->next->ant))))
		tmp_path = tmp_path->next;
	}
	tmp = tmp_path;
	if (tmp->next)
	{
	ft_printf("tmp->room = %s, busy = %d, ft_isdigit() = %s\n", tmp->room, tmp->busy, tmp_path->next->ant);
	while (tmp && tmp->busy == path)
	{
		tmp = tmp_path;
		if (!ft_isdigit(*(tmp->ant)))
			break ;
		while (tmp->next && tmp->next->busy == path && ft_isdigit(*(tmp->next->ant)))
			tmp = tmp->next;
		move_one_ant(tmp, path, store);
	}
	}
	return (0);
}

static int	move_ant_inside(t_lem *new_map, int path_nbr_max, t_store *store)
{
	t_lem	*tmp;
	int		path;

	path = 1;
	tmp = new_map;
	ft_printf("path_nbr_max = %d\n", path_nbr_max);
	while (path <= path_nbr_max)
	{
		ft_printf("path = %d\n", path);
		move_ant_one_path(new_map, path, store);
		path++;
	}
	return (0);
}

static int	insert_new_ant(t_lem *new_map, t_store *store, int path_nbr)
{
	t_lem	*tmp;
	int		i;

	i = 1;
	tmp = new_map;
	ft_printf("ants_strt = %d, busy = %d, path_nbr = %d\n",store->ants_strt, tmp->busy, path_nbr);
	while (tmp && tmp->busy <= path_nbr)
	{
		while (tmp && tmp->busy != i)
			tmp = tmp->next;
		if (tmp && store->ants_strt > 0)
		{
			ft_strcpy(tmp->ant, ft_itoa(store->ants));
			store->ants++;
			store->ants_strt--;
		}
		i++;
	}
		ft_putendl("Moove new ants");
	print_room(new_map);
	return (path_nbr);
}

static int	move_ants(t_lem *new_map, t_store *store, int *size_paths, int path_nbr_max)
{
	int		path_nbr;

	path_nbr = choose_paths(new_map, store, path_nbr_max, &size_paths);
	return (insert_new_ant(new_map, store, path_nbr));
}

int			fill_result(t_lem *new_map, t_store *store, int *size_paths)
{
	int	path_nbr_max;

	path_nbr_max = 0;
	store->ants_tot = store->ants;
	store->ants_strt = store->ants;
	store->ants_end = 0;
	store->ants = 1;
	while (*(size_paths + (path_nbr_max)) != -1)
		path_nbr_max++;
	ft_printf("path_nbr_max = %d", path_nbr_max);
	while (store->ants_end != store->ants_tot)
	//while (store->ants_strt != 0)
	{
		move_ant_inside(new_map, path_nbr_max, store);
		ft_putendl("Moove inside ants");
	print_room(new_map);
		move_ants(new_map, store, size_paths, path_nbr_max);
		ft_putendl("Moove new ants");
	print_room(new_map);
		ft_putchar('\n');
	}
	return (0);
}
