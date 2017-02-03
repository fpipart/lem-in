/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 10:11:50 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/03 12:51:04 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	move_one_tube(t_lem **tmp_path, t_store *store)
{
	t_lem	*tmp;
	int		step;

	step = 0;
	tmp = *tmp_path;
	while (*((*tmp_path)->ant) != '\0')
	{
		tmp = *tmp_path;
		if (step == 0)
		{
			ft_putendl("--------|||||||||||||||||||-----------");
			while (tmp->next && *(tmp->next->ant) != '\0' && tmp->next->busy == tmp->busy)
				tmp = tmp->next;
			if (tmp->next && tmp->busy == tmp->next->busy)
				ft_strcpy(tmp->next->ant, tmp->ant);
			if (!tmp->next || tmp->next->busy != tmp->busy)
				store->ants_end++;
			ft_bzero(tmp->ant, 11);
			step = 1;
			print_room(*tmp_path);
		}
		else if (step == 1)
		{
			ft_putendl("-----------------_________________________-----------");
			while (tmp->next && *(tmp->next->ant) != '\0')
				tmp = tmp->next;
			ft_strcpy(tmp->next->ant, tmp->ant);
			ft_bzero(tmp->ant, 11);
			print_room(*tmp_path);
		}
	}
	return (0);
}

int			move_ant_inside_end(t_lem **new_map, int path_nbr_max, t_store *store)
{
	t_lem	*tmp;
	int		path;

	path = 1;
	tmp = *new_map;
	ft_putendl("START");
	print_room(*new_map);
	while (path <= path_nbr_max)
	{
	ft_printf("PATH = %d\n", path);
		while (tmp && tmp->busy != path)
			tmp = tmp->next;
		while (tmp && *(tmp->ant) == '\0' && tmp->busy == path)
			tmp = tmp->next;
		if (tmp)
			move_one_tube(&tmp, store);
		else
			return (1);
		path++;
	}
	print_room(*new_map);
	ft_printf("PATH = %d\n", path);
	return (0);
}
