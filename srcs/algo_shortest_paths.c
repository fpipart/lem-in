/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sortest_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:00:22 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/27 18:02:56 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	continue_extrem_node(t_lem **lem, t_lem *tmp, char *end, int step)
{
	t_list	*lst;

	lst = tmp->lst;
	while (lst)
	{
		one_step(lem, lst->content, end, step);
		if (ft_strequ(tmp->room, end))
			return (1);
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
		ft_printf("Room act = %s, step = %d\n", tmp->room, step);
		if (tmp->len == step - 1)
			if (continue_extrem_node(lem, tmp, end, step))
				return (1);
		tmp = tmp->next;
	}
	return (0);
}
