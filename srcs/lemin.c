/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:28:17 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/20 17:04:40 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	command(char *line, t_store *store)
{
	if (ft_strequ("##start", line))
		ft_strcpy(store->cmd, "start");
	else if (ft_strequ("##end", line))
		ft_strcpy(store->cmd, "end");
	return (0);
}

static int	handle_room(t_store **store, char **line, t_lem *lem, t_lem *cmd)
{
	int		error;
	t_lem	*new;
	char	**tab;

	error = 0;
	tab = ft_strsplit(*line, ' ');
	if (!(new = (t_lem*)malloc(sizeof(t_lem))) || ft_strchr(tab[0], '-'))
		return (1);
	new->room = tab[0];
	new->coord_x = ft_atoi_checker(tab[1], &error);
	new->coord_y = ft_atoi_checker(tab[2], &error);
	new->busy = 0;
	new->lst = NULL;
	new->next = NULL; 
	ft_bzero(new->cmd, 6); 
	if (error == 1)
		return (1);
	(*store)->nbr_rm++;
	if (*((*store)->cmd) != '\0')
		addelem(&cmd, &new, store);
	addelem(&lem, &new, store);
	return (0);
}

static int	handle_tube(t_store **store, char **line, t_lem *lem, t_lem *cmd)
{

	return (0);
}

static int	store_input(t_store *store)
{
	char	*line;
	t_lem	*lem;
	t_lem	*cmd;
	int		error;

	lem = NULL;
	error = 0;
	store->ants = -1;
	store->tube = 0;
	while (get_next_line(0, &line) && error == 0)
	{
		if (ft_strnequ("##", line, 2))
			command(line, store);
		else if (line[0] == '#' || line[0] == 'L')
			;
		else if (store->ants != -1)
			store->ants = ft_atoi_checker(line, &error);
		else if (ft_wordcount(line, ' ') == 3)
			error = handle_room(&store, &line, lem, cmd);
		else if (ft_wordcount(line, ' ') == 1 && ft_strchr(line, '-'))
			error = handle_tube(&store, &line, lem, cmd);
		print_room(lem);
	}
	return (0);
}

int			main()
{
	t_store store;

	store_input(&store);
	return (0);
}
