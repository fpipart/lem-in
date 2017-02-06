/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:28:17 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/06 18:55:14 by fpipart          ###   ########.fr       */
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

void	store_cmd(t_store *store, char *cmd, char *room)
{
	if (ft_strequ(cmd, "start"))
		store->start = room;
	if (ft_strequ(cmd, "end"))
		store->end = room;
}

static int	handle_nbr(t_store *store, char *line, t_lem **lem)
{
	int error;

	error = 0;
	(void)lem;
	if (*(store)->cmd != '\0')
		return (1);
	store->ants = ft_atoi_checker(line, &error);
	return (error);
}

static int	handle_room(t_store *store, char *line, t_lem **lem)
{
	int		error;
	t_lem	*new;
	char	**tab;

	error = 0;
	tab = ft_strsplit(line, ' ');
	if (ft_wordcount(line, ' ') != 3 || ft_strchr(tab[0], '-')
			|| !(new = (t_lem*)malloc(sizeof(t_lem))))
	{
		free_tab(tab, ft_wordcount(line, ' '));
		return (1);
	}
	new->room = tab[0];
	new->crd_x = ft_atoi_checker(tab[1], &error);
	new->crd_y = ft_atoi_checker(tab[2], &error);
	new->busy = 0;
	new->len = -1;
	new->lst = NULL;
	new->next = NULL;
	free(&tab[0]);
	ft_bzero(new->ant, 11);
	if (error)
		return (1);
	store->nbr_rm++;
	if (*(store->cmd) != '\0')
		store_cmd(store, store->cmd, new->room);
	return (addelem(lem, new, store));
}

static int	handle_tube(t_store *store, char *line, t_lem **lem)
{
	int		error;
	char	**tab;

	error = 0;
	tab = ft_strsplit(line, '-');
	if (ft_wordcount(line, '-') != 2 || ft_wordcount(line, ' ') != 1)
		return (error += 1);
	(store)->tube++;
	error += add_connection(lem, tab);
	return (error);
}

static int	select_parsing_f(t_store *store, char *line,
		t_lem **lem)
{
	static int	(*f[3])
		(t_store *store, char *line, t_lem **lem) = {
			&handle_nbr,
			&handle_room,
			&handle_tube,
		};

	if ((store)->ants > 0 && (store)->nbr_rm == 0)
		(store)->step = 1;
	else if ((store)->nbr_rm > 0 && (store)->tube == 0
			&& ft_wordcount(line, '-') == 2 && ft_wordcount(line, ' ') == 1)
		(store)->step = 2;
	return (f[(store)->step](store, line, lem));
}

static int	store_input(t_store *store, t_lem **lem)
{
	char		*line;
	int			error;
	int			step;

	step = 0;
	error = 0;
	line = NULL;
	while (error == 0 && get_next_line(0, &line))
	{
		if (line[0] == '#' || line[0] == 'L')
			command(line, store);
		else
			error += select_parsing_f(store, line, lem);
		free(line);
	}
//	check_validity()
	return (0);
}

int			main()
{
	t_store store;
	t_lem	*lem;

	lem = NULL;
	store = init_store();
	store_input(&store, &lem);
	if (lem)
		resolve(lem, &store);
	del_lst(&lem);
	return (0);
}
