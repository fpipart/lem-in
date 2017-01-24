/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:42:59 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/24 15:18:04 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	addtolist(t_lem **old, t_lem *new, t_store *store)
{
	t_lem *tmp;
	t_lem *tmp2;

	tmp = *old;
	while (tmp &&
			((new->crd_x != tmp->crd_x || new->crd_y != tmp->crd_y)))
		tmp = tmp->next;
	if (tmp)
	{
		tmp2 = *old;
		if (*old != tmp)
		{
			while (tmp2->next != tmp)
				tmp2 = tmp2->next;
			new->next = tmp->next;
			tmp2->next = new;
		free(tmp);
		}
		else
		{
			new->next = (*old)->next;
			*old = new;
		}
		store->nbr_rm--;
	print_room(*old);
	}
	else
	{
		tmp = new;
		tmp->next = *old;
		*old = tmp;
	}
	return (0);
}

int			addelem(t_lem **old, t_lem *new, t_store *store)
{
	if (*old)
		addtolist(old, new, store);
	else
		*old = new;
	if (ft_strequ(store->cmd, "start") || ft_strequ(store->cmd, "end"))
		ft_strcpy((*old)->cmd, store->cmd);
	if (*store->cmd != '\0')
		ft_bzero(store->cmd, 6);
	return (0);
}

void		print_room(t_lem *room)
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

t_store	init_store(void)
{
	t_store store;

	store.ants = -1;
	store.tube = 0;
	store.nbr_rm = 0;
	store.step = 0;
	ft_bzero(store.cmd, sizeof(char) * 6);
	return (store);
}

void	free_tab(char **tab, int word)
{
	int i;

	i = 0;
	while (i < word)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
