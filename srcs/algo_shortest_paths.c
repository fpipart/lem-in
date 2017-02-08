/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sortest_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:00:22 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/08 12:08:44 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	continue_extrem_node(t_lem **lem, t_lem *tmp, t_store *store, int step)
{
	t_list	*lst;

	lst = tmp->lst;
	while (lst)
	{
		if (one_step(lem, lst->content, store, step))
			return (1);
		lst = lst->next;
	}
	return (0);
}

int			select_room(t_lem **lem, t_store *store, int step)
{
	t_lem	*tmp;

	tmp = *lem;
	while (tmp)
	{
	//	ft_printf("step - 1 = %d, tmp->len = %d, tmp->room = %s\n", step - 1, tmp->len, tmp->room);
		if (tmp->len == step - 1 && tmp->busy == 0)
			if (continue_extrem_node(lem, tmp, store, step))
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_lem	*find_linked_rm(char *room, t_lem **lem)
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
		if (tmp2->len == 0 && step == 1)
			return (0);
		else if (tmp2->len == step - 1 && tmp2->busy == 0)
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
		if (tmp->len && tmp->busy == 0)
			tmp->len = -1;
		tmp = tmp->next;
	}
}
