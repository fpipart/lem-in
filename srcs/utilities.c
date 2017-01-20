/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:42:59 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/20 16:44:20 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	addelem(t_lem **old, t_lem **new, t_store **store)
{
	t_lem *tmp;

	if (*old)
	{
		tmp = *new;
		tmp->next = *old;
		*old = tmp;
	}
	else
		*old = *new;
	if (ft_strequ((*store)->cmd, "start") || ft_strequ((*store)->cmd, "end"))
	{
		ft_strcpy((*old)->cmd, (*store)->cmd);
		ft_bzero((*store)->cmd, 6);
	}
	return (0);
}

void	print_room(t_lem *room)
{
	t_lem	*tmp;

	if (room)
	{
		tmp = room;
		while (tmp)
		{
			ft_printf("%d\n", tmp->room);
			tmp = tmp->next;
		}
	}
}
