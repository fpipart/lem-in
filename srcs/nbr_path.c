/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:28:53 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/09 15:52:35 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	find_pathlength(t_lem *new_map, int path)
{
	int		len;
	t_lem	*tmp;

	tmp = new_map;
	len = 0;
	while (tmp)
	{
		if (tmp->busy == path)
			len++;
		tmp = tmp->next;
	}
	return (len + 1);
}

int			choose_paths(t_lem *new_map, t_store *store, int path_nbr,
		int **size_paths)
{
	int i;
	int step;

	step = 0;
	i = 0;
	while (i < path_nbr)
	{
		if (store->start_end == 1 && i == 0)
			(*size_paths)[0] = 1;
		else
			(*size_paths)[i] = find_pathlength(new_map, i + 1);
		if (step == 0)
			step = store->ants_strt + (*size_paths)[0];
		else
			step -= (*size_paths)[i];
		i++;
		if (step < 0)
			break ;
	}
	(*size_paths)[i] = -1;
	if (step < 0)
		i--;
	return (i);
}
