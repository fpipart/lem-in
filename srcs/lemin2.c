/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:38:40 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/11 14:08:30 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			command(char *line, t_store *store)
{
	if (ft_strequ("##start", line))
		ft_strcpy(store->cmd, "start");
	else if (ft_strequ("##end", line))
		ft_strcpy(store->cmd, "end");
	return (0);
}

void		store_cmd(t_store *store, char *cmd, char *room)
{
	if (ft_strequ(cmd, "start"))
		store->start = room;
	if (ft_strequ(cmd, "end"))
		store->end = room;
}

void		init_new_lem(char **tab, t_lem **new, int *error)
{
	(*new)->room = tab[0];
	(*new)->crd_x = ft_atoi_checker(tab[1], error);
	(*new)->crd_y = ft_atoi_checker(tab[2], error);
	(*new)->busy = 0;
	(*new)->len = -1;
	(*new)->lst = NULL;
	(*new)->next = NULL;
	free(&tab[0]);
	ft_bzero((*new)->ant, 11);
}

int			handle_nbr(t_store *store, char *line, t_lem **lem)
{
	int error;

	error = 0;
	(void)lem;
	if (*(store)->cmd != '\0')
		return (1);
	store->ants = ft_atoi_checker(line, &error);
	return (error);
}
