/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reshap_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:18:48 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/31 14:28:08 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

int		reshap_map(t_lem *lem, t_lem *new_map, t_store *store, int path_nbr)
{
	
	return (0);
}
