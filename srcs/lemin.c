/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:28:17 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/19 18:55:42 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_lem	*handle_room(t_store *store, char **line, t_lem *lem)
{
	int		i;
	int		word_1;
	t_lem	new;
	char	**tab;

	word_1 = 0;
	tab = ft_strsplit(*line, ' ');
	if (ft_strchr(tab[0], '-'))
	{
		//Del debut de list
		return (NULL);
	}
	else
		lem->room = tab[0];
	ft_atoi
	return (lem);
}

static int		handle_tube(t_store *store, char **line, t_lem *lem)
{

	return (0);
}

static int		store_input(t_store *store)
{
	char	*line;
	t_lem	*lem;

	lem = NULL;
	store->nbr_a = -1;
	store->tube = 0;
	while (get_next_line(0, &line))
	{
		if (line[0] == '#' || line[0] == 'L')
			;
		else if (store->nbr_a != -1)
			store->nbr_a = ft_atoi(line);
		else if (ft_wordcount(line, ' ') == 3)
			lem = handle_room(store, &line, lem);
		else if (ft_wordcount(line, ' ') == 1 && ft_strchr(line, '-'))
			lem = handle_tube(store, &line, lem);
	}
	return (0);
}

int				main()
{
	t_store store;

	store_input(&store);
	return (0);
}
