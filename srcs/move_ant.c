/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 10:11:50 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/06 18:09:40 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	insert_new_ant(t_lem *new_map, t_store *store, int path_nbr)
{
	t_lem	*tmp;
	int		i;

	i = 1;
	tmp = new_map;
	while (tmp && tmp->busy <= path_nbr)
	{
		while (tmp && tmp->busy != i)
			tmp = tmp->next;
		if (tmp && store->ants_strt > 0)
		{
			ft_strcpy(tmp->ant, ft_itoa(store->ants));
			print_ant_position(tmp->ant, tmp->room);
			store->ants++;
			store->ants_strt--;
		}
		i++;
	}
	return (path_nbr);
}

int	move_ants(t_lem *new_map, t_store *store, int *size_paths,
		int path_nbr_max)
{
	int	path_nbr;

	path_nbr = choose_paths(new_map, store, path_nbr_max, &size_paths);
	return (insert_new_ant(new_map, store, path_nbr));
}

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
			while (tmp->next && *(tmp->next->ant) != '\0' &&
					tmp->next->busy == tmp->busy)
				tmp = tmp->next;
			if (tmp->next && tmp->busy == tmp->next->busy)
			{
				ft_strcpy(tmp->next->ant, tmp->ant);
				print_ant_position(tmp->next->ant, tmp->next->room);
			}
			else if (!tmp->next || tmp->next->busy != tmp->busy)
			{
				store->ants_end++;
				print_ant_position(tmp->ant, store->end);
			}
			ft_bzero(tmp->ant, 11);
			step = 1;
		}
		else if (step == 1)
		{
			while (tmp->next && *(tmp->next->ant) != '\0')
				tmp = tmp->next;
			ft_strcpy(tmp->next->ant, tmp->ant);
			print_ant_position(tmp->next->ant, tmp->next->room);
			ft_bzero(tmp->ant, 11);
		}
	}
	return (0);
}

int			move_ant_inside_end(t_lem **new_map, int path_nbr_max, t_store *store)
{
	t_lem	*tmp;
	int		path;
	int		end_nbr;

	end_nbr = store->ants_end;
	path = 1;
	tmp = *new_map;
	while (path <= path_nbr_max)
	{
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
	return (store->ants_end - end_nbr);
}
