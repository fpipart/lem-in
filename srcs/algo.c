/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:05:24 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/28 17:16:11 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			one_step(t_lem **lem, char *room, char *end, int step)
{
	t_lem	*tmp;

	tmp = *lem;
	while (!ft_strequ(tmp->room, room))
		tmp = tmp->next;
	if (tmp->busy == 0 && (tmp->len > step || tmp->len == -1))
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
	int	end_index;
	int	select_path;
	int	step;

	select_path = store->ants;
	step = 1;
	end_index = 0;
	if (set_start(lem, store))
		return (1);
	while (select_path > 0)
	{
		if (select_room(lem, store->end, step))
		{
			end_index += 1;
			if (select_path == store->ants)
				select_path = select_path + step - 1;
			else
				select_path = select_path - step;
			if (set_busy(lem, store->end, end_index, step) && select_path > 0)
				return (1);
			step = 1;
			ft_putendl("coucouocuuoc");
			restart_len(lem);
		print_room(*lem);
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
	if (find_shortest_paths(&lem, store))
		return (1);
	ft_putendl("Fin");
	print_room(lem);
	return (0);
}
