/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:42:59 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/20 18:20:57 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	addelem(t_lem **old, t_lem **new, t_store **store)
{
	t_lem *tmp;

	if (*old)
	{
		tmp = *old;
		while (tmp &&
		(((*new)->crd_x != tmp->crd_x || (*new)->crd_y != tmp->crd_y)))
			tmp = tmp->next;
		if (tmp)
		{
			(*new)->next = tmp->next;
			tmp = *new;
			*old = tmp;
		}
		else
		{
			tmp = *new;
			tmp->next = *old;
			*old = tmp;
		}
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
			ft_printf("%s\n", tmp->room);
			tmp = tmp->next;
		}
	}
}
