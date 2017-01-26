/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:05:24 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/26 18:22:04 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_lem	*select_cmd(t_lem *cmd)
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
	while (tmp)
	{
		if (ft_strequ(tmp->cmd, "end"))
			break ;
		tmp = tmp->next;
	}
	tmp->next = tmp2;
	tmp2->next = NULL;
	return (tmp);
}

static int	one_step(t_lem **lem, char *room, int step)
{
	t_lem	*tmp;

	tmp = *lem;
	while (!ft_strequ(tmp->room, room))
		tmp = tmp->next;
	tmp->len = step;
	return (0);
}

static int	set_start(t_lem **lem, t_lem *st_nd)
{
	t_lem	*tmp;
	t_list	*lst;

	tmp = *lem;
	while (!ft_strequ(st_nd->room, tmp->room))
		tmp = tmp->next;
	lst = tmp->lst;
	while (lst)
	{
		one_step(lem, lst->content, 1);
		lst = lst->next;
	}
	return (0);
}

static int	find_shortest_paths(t_lem **lem, t_lem *st_nd)
{
	int end;
	int step;

	end = 0;
	step = 2;
	set_start(lem, st_nd);
	while (end == 0)
	{
		end = continue_extrem_node(lem, st_nd->next->room, step);
		step++;
	}
	return (0);
}

int		resolve(t_lem *lem, t_lem *cmd, t_store *store)
{
	t_lem	*start_end;

	start_end = NULL;
	start_end = select_cmd(cmd);
	find_shortest_paths(&lem, cmd);
	return (0);
}
