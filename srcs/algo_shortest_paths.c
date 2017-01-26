/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sortest_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:00:22 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/26 18:24:19 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*select_room(t_lem *lem, int step)
{
	t_lem *tmp;

	tmp = lem;
	while ()
	step - 1
}

int		continue_extrem_node(t_lem **lem, char *end, int step)
{
	t_lem	*tmp;
	char	*room;

	tmp = *lem;
	room = NULL;
	while (room = select_room())
	{
	while (!ft_strequ(room, tmp->room))
		tmp = tmp->next;
	tmp->len = step;
	if (ft_strequ(room, end))
		return (1);
	}
	return (0);
}
