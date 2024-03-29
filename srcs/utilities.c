/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:42:59 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/09 11:31:21 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	replace_node(t_lem *tmp, t_lem **old, t_lem *new)
{
	t_lem *tmp2;

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
	return (0);
}

static int	addtolist(t_lem **old, t_lem *new, t_store *store)
{
	t_lem *tmp;

	tmp = *old;
	while (tmp && !ft_strequ(new->room, tmp->room) &&
	((new->crd_x != tmp->crd_x || new->crd_y != tmp->crd_y)))
		tmp = tmp->next;
	if (tmp && ((new->crd_x == tmp->crd_x && new->crd_y == tmp->crd_y)
	|| ft_strequ(new->room, tmp->room)))
	{
		replace_node(tmp, old, new);
		store->nbr_rm--;
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
	if (*store->cmd != '\0')
		ft_bzero(store->cmd, 6);
	return (0);
}

t_store		init_store(void)
{
	t_store store;

	store.ants = -1;
	store.tube = 0;
	store.nbr_rm = 0;
	store.step = 0;
	ft_bzero(store.cmd, 6);
	store.start = NULL;
	store.end = NULL;
	store.start_end = 0;
	return (store);
}

void		free_tab(char **tab, int word)
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
