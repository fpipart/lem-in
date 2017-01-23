/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:42:59 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/23 19:24:32 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	addtolist(t_lem **old, t_lem **new, t_store **store)
{
	t_lem *tmp;
	t_lem *tmp2;

	tmp = *old;
	ft_putendl("1");
	ft_printf("room = %s\n",(tmp->room));
	while (tmp &&
			(((*new)->crd_x != tmp->crd_x || (*new)->crd_y != tmp->crd_y)))
		tmp = tmp->next;
	ft_putendl("2");
	if (tmp && *(*store)->cmd == '\0')
	{
		tmp2 = *old;
		while (*old != tmp && tmp2->next != tmp)
			tmp2 = tmp2->next;
	ft_putendl("3");
		tmp2->next = (*new);
		(*new)->next = tmp->next;
		free(tmp);
		(*store)->nbr_rm--;
	ft_putendl("4");
	}
	else
	{
		ft_putendl("5");
		tmp = *new;
		tmp->next = *old;
		*old = tmp;
	}
	return (0);
}

int			addelem(t_lem **old, t_lem **new, t_store **store)
{
	if (*old)
		addtolist(old, new, store);
	else
		*old = *new;
	if (ft_strequ((*store)->cmd, "start") || ft_strequ((*store)->cmd, "end"))
		ft_strcpy((*old)->cmd, (*store)->cmd);
	if (*(*store)->cmd != '\0')
		ft_bzero((*store)->cmd, 6);
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

void	init_store(t_store **store)
{
	(*store)->ants = -1;
	(*store)->tube = 0;
	(*store)->nbr_rm = 0;
	(*store)->step = 0;
	ft_bzero((*store)->cmd, 6);
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
