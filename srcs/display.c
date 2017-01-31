/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:44:07 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/31 14:11:24 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		move_ant_inside(t_lem *src, t_lem *dest)
{
	
	return (0);
}

static int	move_ants(t_lem *lem, t_store *store, int *tab)
{
	int		path_nbr;
	t_lem	*tmp;

	path_nbr = 0;
	while (*(tab + path_nbr) != -1)
		path_nbr++;
	path_nbr = choose_paths(lem, store, path_nbr, tab);
	tmp = lem;
	while (tmp)
	{
		move_ant_inside(tmp, lem);
		tmp = tmp->next;
	}
	return (path_nbr);
}

int			display_result(t_lem *lem, t_store *store, int *tab)
{
	int ant;
	int i;

	ant = 1;
	while (ant <= store->ants)
	{
		manage_path(lem, store);
		ant += move_ants(lem, store, tab); 
		ft_putchar('\n');
	}
	return (0);
}
