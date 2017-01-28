/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sortest_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:00:22 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/28 15:46:51 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	continue_extrem_node(t_lem **lem, t_lem *tmp, char *end, int step)
{
	t_list	*lst;

	lst = tmp->lst;
	while (lst)
	{
		if (one_step(lem, lst->content, end, step))
		{
			ft_printf("find end : len = %d, Room = %s\n", tmp->len, tmp->room);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

int			select_room(t_lem **lem, char *end, int step)
{
	t_lem	*tmp;

	tmp = *lem;
	while (tmp)
	{
		if (tmp->len == step - 1)
		{
			ft_printf("select_room : len = %d, Room - 1 = %s\n", tmp->len, tmp->room);
			if (continue_extrem_node(lem, tmp, end, step))
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static t_lem	*find_linked_rm(char *room, t_lem **lem)
{
	t_lem *tmp;

	tmp = *lem;
	while (tmp)
	{
		if (ft_strequ(room, tmp->room))
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

int		set_busy(t_lem **lem, char *room, int end_index, int step)
{
	t_lem	*tmp;
	t_lem	*tmp2;
	t_list	*lst;

	tmp = *lem;
	while (tmp)
	{
		if (ft_strequ(room, tmp->room))
			break ;
		tmp = tmp->next;
	}
	lst = tmp->lst;
	tmp->busy = end_index;
	while (lst)
	{
		tmp2 = find_linked_rm(lst->content, lem);
		ft_printf("room = %s, tmp2->len = %d, step - 1 = %d\n", tmp2->room, tmp2->len, step - 1);
		if (tmp2->len == 0)
			return (0);
		else if (tmp2->len == step - 1)
			return (set_busy(lem, tmp2->room, end_index, step - 1));
		lst = lst->next;
	}
	return (1);
}

void	restart_len(t_lem **lem)
{
	t_lem	*tmp;

	tmp = *lem;
	while (tmp)
	{
		if (tmp->len)
			tmp->len = -1;
		tmp = tmp->next;
	}
}
