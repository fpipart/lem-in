/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:05:24 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/30 14:56:52 by fpipart          ###   ########.fr       */
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
	nbr_max = manage_path(*lem, store);
	if (set_start(lem, store))
		return (-1);
	while (nbr_path < nbr_max)
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
	return (0);
}

int			resolve(t_lem *lem, t_store *store)
{
	ft_putendl("Path finding");
	ft_putendl(store->start);
	ft_putendl(store->end);
	if (find_shortest_paths(&lem, store) == -1)
		return (1);
	print_room(lem);
	return (0);
}
