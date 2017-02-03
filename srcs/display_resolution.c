/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:48:02 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/03 15:12:47 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
static int	find_min(t_lem *map)
{
	t_lem	*tmp;
	int		min;

	tmp = map;
	min = ft_atoi(tmp->ant);
	while (tmp)
	{
		if (ft_atoi(tmp->ant) < min)
			min = ft_atoi(tmp->ant);
		tmp = tmp->next;
	}
	return (min);
}

int		print_resolution(t_lem *map, int nbr_end)
{
	t_lem	*tmp;
	int		min;

	min = find_min(map);
	tmp = map;
	while ()
	{
	}
	return (0);
}
