/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:05:24 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/27 19:44:44 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	select_cmd(t_lem *cmd, t_store *store)
{
	t_lem *tmp;
	t_lem *tmp2;

	tmp = cmd;
	while (tmp)
	{
		if (ft_strequ(tmp->cmd, "start"))
			break ;
		tmp = tmp->next;
	}
	tmp2 = cmd;
	while (tmp2)
	{
		if (ft_strequ(tmp2->cmd, "end"))
			break ;
		tmp2 = tmp2->next;
	}
	if (!tmp || !tmp2)
		return (1);
	store->start = tmp->room;
	store->end = tmp2->room;
	return (0);
}

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
	int	end_index;
	int	select_path;
	int	step;

	select_path = store->ants;
	step = 1;
	if (set_start(lem, store))
		return (1);
	while (select_path > 0 && step < 10)
	{
		end_index = select_room(lem, store->end, step);
		if (path_len == 1)
		{
		}
		if (select_path == store->ants)
			select_path = select_path + path_len - 1;
		else
			select_path = select_path - step;
		step++;
	}
	return (0);
}

int			resolve(t_lem *lem, t_lem *cmd, t_store *store)
{
	ft_putendl("Path finding");
	if (select_cmd(cmd, store))
		return (1);
	if (find_shortest_paths(&lem, store))
		return (1);
	print_room(lem);
	return (0);
}
