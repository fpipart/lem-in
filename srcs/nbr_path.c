/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:28:53 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/01 16:37:43 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int find_pathlength(t_lem *new_map, int path)
{
	int		len;
	t_lem	*tmp;

	tmp = new_map;
	len = 0;
	while (tmp->busy == path)
	{
		tmp = tmp->next;
		len++;
	}
//	if (path > 1)
//		len++;
	return (len);
}

int		choose_paths(t_lem *new_map, t_store *store, int path_nbr, int **size_paths)
{
	int i;
	int step;

	step = 0;
	i = 0;
	while (i < path_nbr && size_paths[i] >= 0)
	{
		(*size_paths)[0] = find_pathlength(new_map, 1);
		if (step == 0)
			step = store->ants + (*size_paths)[0];
		else
			step -= (*size_paths)[i];
		i++;
	}
	(*size_paths)[i] = -1;
	return (i);
}
/*
static int find_pathlength(t_lem *lem, char *end, int path)
{
	int		len;
	t_lem	*tmp;
	t_list	*lst;

	tmp = lem;
	len = 0;
	while (ft_strequ(end, tmp->room))
		tmp = tmp->next;
	lst = tmp->lst;
	while (lst)
	{
		tmp = lem;
		while (ft_strequ(lst->content, tmp->room))
			tmp = tmp->next;
		if (tmp->busy == path)
		{
			len = tmp->len;
			break ;
		}
	}
	return (len);
}

int		choose_paths(t_lem *lem, t_store *store, int path_nbr, int *size_paths)
{
	int i;
	int step;
	int size_path;

	step = 0;
	i = 0;
	while (i < path_nbr && size_path >= 0)
	{
		size_path = find_pathlength(lem, store->end, 1);
		size_paths[0] = size_path;
		if (step == 0)
			step = store->ants + size_path;
		else
			step -= size_path;
		i++;
	}
	size_paths[i] = -1;
	return (i);
}*/
