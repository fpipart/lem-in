/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:11:50 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/09 10:15:31 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static	int	check_start_end(t_store store, t_lem *lem)
{
	t_lem	*tmp;
	int		end;
	int		start;

	end = 0;
	start = 0;
	tmp = lem;
	while (tmp)
	{
		if (ft_strequ(tmp->room, store.start))
			start = 1;
		else if (ft_strequ(tmp->room, store.end))
			end = 1;
		tmp = tmp->next;
	}
	if (start != 1 || end != 1)
	{
		print_error();
		return (1);
	}
	return (0);
}

int			check_validity(t_store store, t_lem *lem)
{
	if (check_start_end(store, lem))
		return (1);
	return (0);
}

int			check_path(t_store *store, t_lem *lem)
{
	t_lem	*tmp;

	tmp = lem;
	while (tmp)
	{
		if (tmp->busy == 1)
			return (0);
		tmp = tmp->next;
	}
	if (store->start_end)
		return (0);
	print_error();
	return (1);
}

void		print_error(void)
{
	ft_putendl("ERROR");
}
