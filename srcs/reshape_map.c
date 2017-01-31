/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reshap_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:18:48 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/31 18:45:14 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	push_back(t_lem **path, t_lem *new_node)
{
	t_lem *tmp;

	tmp = *path;
	if (path && *path)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	else
		*path = new_node;
}

static t_lem	*new_node(t_lem *lem)
{
	t_lem *node;

	node = (t_lem*)malloc(sizeof(t_lem));
	node->room = ft_strdup(lem->room);
	ft_bzero(node->ant, 10);
	node->crd_x = lem->crd_x;
	node->crd_y = lem->crd_y;
	node->busy = lem->busy;
	node->len = lem->len;
	node->next = NULL;
	node->lst = NULL;
	return (node);
}

int		reshape_map(t_lem *lem, t_lem **new_map, t_store *store, int path_nbr)
{
	int		i;
	int		j;
	t_lem	*tmp;

	i = 1;
	(void)store;
	while (i <= path_nbr)
	{
		j = 1;
		while (tmp)
		{
			tmp = lem;
			while (tmp && (i != tmp->busy || j != tmp->len))
				tmp = tmp->next;
			if (tmp && tmp->busy == i)
				push_back(new_map, new_node(tmp));
			j++;
		}
		i++;
	}
	return (0);
}
