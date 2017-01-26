/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sortest_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:00:22 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/26 19:16:36 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	continue_extrem_node(t_lem **lem, char *room, char *end, int step)
{
	t_lem	*tmp;

	tmp = *lem;
	while ()
	{
	while (!ft_strequ(room, tmp->room))
		tmp = tmp->next;
	tmp->len = step;
	if (ft_strequ(room, end))
		return (1);
	}
	return (0);
}

int		select_room(t_lem **lem, char *end, int step)
{
	t_lem *tmp;

	tmp = *lem;
	while (tmp)
	{
		if (tmp->len == step - 1 && !ft_strequ(tmp->room, end))
			continue_extrem_node(lem, tmp->room, end, step);
		if (ft_strequ(tmp->room, end))
			return (1);
		tmp = tmp->next;
	}
}
