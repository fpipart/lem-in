/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:28:53 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/31 12:27:58 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

int		choose_paths(t_lem *lem, t_store *store, int path_nbr, int *tab)
{
	int i;
	int step;
	int size_path;

	step = 0;
	i = 0;
	while (i < path_nbr && size_path >= 0)
	{
		size_path = find_pathlength(lem, store->end, 1);
		tab[0] = size_path;
		if (step == 0)
			step = store->ants + size_path;
		else
			step -= size_path;
		i++;
	}
	tab[i] = -1;
	return (i);
}
