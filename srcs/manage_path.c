/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:07:27 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/30 14:37:53 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int count_path(t_list *start, t_list *end)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = start;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = end;
	while (tmp)
	{
		tmp = tmp->next;
		j++;
	}
	if (i < j)
		return (i);
	return (j);
}

int		manage_path(t_lem *lem, t_store *store)
{
	t_lem	*start;
	t_lem	*end;
	int		nbr_path_max;

	start = find_linked_rm(store->start, &lem);
	end = find_linked_rm(store->end, &lem);
	nbr_path_max = count_path(start->lst, end->lst);
	return (nbr_path_max);
}
