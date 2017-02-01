/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:05:24 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/01 18:32:54 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			one_step(t_lem **lem, char *room, char *end, int step)
{
	t_lem	*tmp;

	tmp = *lem;
	while (!ft_strequ(tmp->room, room))
		tmp = tmp->next;
	if ((tmp->len > step || tmp->len == -1) && tmp->busy == 0)
		tmp->len = step;
	if (ft_strequ(end, room))
		return (1);
	return (0);
}

static int	set_start(t_lem **lem, t_store *store)
{
	t_lem	*tmp;
	t_list	*lst;

	tmp = *lem;
	ft_putendl("Find start tube");
	while (tmp && !ft_strequ(store->start, tmp->room))
		tmp = tmp->next;
	ft_putendl(tmp->room);
	if (!tmp)
		return (1);
	tmp->len = 0;
	lst = tmp->lst;
	return (0);
}

static int	find_shortest_paths(t_lem **lem, t_store *store)
{
	int	step;
	int nbr_max;
	int nbr_path;

	step = 1;
	nbr_path = 0;
	nbr_max = nbr_path_max(*lem, store);
	if (set_start(lem, store))
		return (-1);
	while (nbr_path < nbr_max && step < store->ants)
	{
		if (select_room(lem, store->end, step))
		{
			nbr_path++;
			if (set_busy(lem, store->end, nbr_path, step))
				return (1);
			step = 0;
			restart_len(lem);
		}
		step++;
	}
	restart_len(lem);
	return (nbr_path);
}

int			resolve(t_lem *lem, t_store *store)
{
	int		path_nbr;
	int		*tab;
	t_lem	*new_map;

	path_nbr = 0;
	new_map = NULL;
	ft_putendl("Path finding");
	ft_putendl(store->start);
	ft_putendl(store->end);
	path_nbr = find_shortest_paths(&lem, store);
	if (path_nbr == -1)
		return (1);
	if (!(tab = (int*)malloc(sizeof(int) * (path_nbr + 1))))
		return (1);
	print_room(lem);
	reshape_map(lem, &new_map, store, path_nbr);
	ft_putendl("new_map");
	print_room(new_map);
	choose_paths(new_map, store, path_nbr, tab);
	fill_result(new_map, store, tab);
	free(tab);
//	print_result
	return (0);
}
