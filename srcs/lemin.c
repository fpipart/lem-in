/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:28:17 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/23 19:05:46 by fpipart          ###   ########.fr       */
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

static int	handle_nbr(t_store **store, char **line, t_lem **lem, t_lem **cmd)
{
	int error;

	error = 0;
	(void)cmd;
	(void)lem;
	if (*(*store)->cmd != '\0')
		return (1);
	(*store)->ants = ft_atoi_checker(*line, &error);
	return (error);
}

static int	handle_room(t_store **store, char **line, t_lem **lem, t_lem **cmd)
{
	int		error;
	t_lem	*new;
	char	**tab;

	error = 0;
	tab = ft_strsplit(*line, ' ');
	if (ft_wordcount(*line, ' ') != 3 || ft_strchr(tab[0], '-')
			|| !(new = (t_lem*)malloc(sizeof(t_lem))))
	{
		free_tab(tab, ft_wordcount(*line, ' '));
		return (1);
	}
	new->room = tab[0];
	new->crd_x = ft_atoi_checker(tab[1], &error);
	new->crd_y = ft_atoi_checker(tab[2], &error);
	new->busy = 0;
	new->lst = NULL;
	new->next = NULL; 
	ft_bzero(new->cmd, 6);
	if (error)
		return (1);
	(*store)->nbr_rm++;
	if (*((*store)->cmd) != '\0')
		addelem(cmd, &new, store);
	return (addelem(lem, &new, store));
}

static int	handle_tube(t_store **store, char **line, t_lem **lem, t_lem **cmd)
{
	int		error;
	char	**tab;

	(void)cmd;
	error = 0;
	tab = ft_strsplit(*line, '-');
	if (ft_wordcount(*line, '-') != 2 || ft_wordcount(*line, ' ') != 1)
		return (error += 1);
	(*store)->tube++;
	error += add_connection(lem, tab);
	return (error);
}

static int	select_parsing_f(t_store **store, char **line,
		t_lem **lem, t_lem **cmd)
{
	static int	(*f[3])
		(t_store **store, char **line, t_lem **lem, t_lem **cmd) = {
			&handle_nbr,
			&handle_room,
			&handle_tube,
		};

	if ((*store)->ants > 0 && (*store)->nbr_rm == 0)
		(*store)->step++;
	else if ((*store)->nbr_rm > 0 && (*store)->tube == 0
			&& ft_wordcount(*line, '-') == 2 && ft_wordcount(*line, ' ') == 1)
		(*store)->step++;
	ft_printf("step = %d, word(-) = %d, word( ) = %d\n", (*store)->step, ft_wordcount(*line, '-'), ft_wordcount(*line, ' '));
	return (f[(*store)->step](store, line, lem, cmd));
}

static int	store_input(t_store **store, t_lem **lem, t_lem **cmd)
{
	char		*line;
	int			error;
	int			step;

	step = 0;
	error = 0;
	while (error == 0 && get_next_line(0, &line))
	{
		if (line[0] == '#' || line[0] == 'L')
			command(line, *store);
		else
		{
			error += select_parsing_f(store, &line, lem, cmd);
			ft_printf("error = %d\n", error);
		}
		ft_putendl("boucle");
	}
	print_room(*lem);
	return (0);
}

int			main()
{
	t_store *store;
	t_lem	*lem;
	t_lem	*cmd;

	lem = NULL;
	cmd = NULL;
	init_store(&store);
	store_input(&store, &lem, &cmd);
	return (0);
}
