/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:28:17 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/11 14:50:12 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
	init_new_lem(tab, &new, &error);
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

static int	select_parsing_f(t_store *store, char *line, t_lem **lem)
{
	static int	(*f[3])(t_store *store, char *line, t_lem **lem) = {
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

static int	store_input(t_store *store, t_lem **lem, t_list **lst)
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
		if (error == 0 && line[0] != 'L')
		{
			if (!*lst)
				*lst = ft_lstnew(line, ft_strlen(line) + 1);
			else if (lst)
				ft_lstadd(lst, ft_lstnew(line, ft_strlen(line) + 1));
		}
		free(line);
	}
	return (0);
}

int			main(void)
{
	t_store store;
	t_lem	*lem;
	t_list	*lst;

	lem = NULL;
	lst = NULL;
	store = init_store();
	store_input(&store, &lem, &lst);
	if (check_validity(store, lem))
		return (0);
	if (lem)
		resolve(lem, &store, lst);
	del_lst(&lem);
	return (0);
}
