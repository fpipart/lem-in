/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_tube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:04:12 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/06 12:44:22 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	findroom_addtube(t_lem **lem, char *room, char *dest)
{
	t_lem	*tmp1;
	t_list	*tmp2;
	t_list	*new;

	tmp1 = *lem;
	while (tmp1 && !ft_strequ(tmp1->room, room))
		tmp1 = tmp1->next;
	if (!tmp1)
		return (1);
	tmp2 = tmp1->lst;
	while (tmp2 && !ft_strequ(tmp2->content, dest))
		tmp2 = tmp2->next;
	if (!tmp2)
	{
		new = ft_lstnew(dest, ft_strlen(dest) + 1);
		ft_lstadd(&tmp1->lst, new); 
	}
	return (0);
}

static int	check_tub(t_lem *lem, char **tab)
{
	t_lem *tmp;

	tmp = lem;
	while (tmp)
	{
		if (ft_strequ(tmp->room, tab[0]))
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
		return (1);
	tmp = lem;
	while (tmp)
	{
		if (ft_strequ(tmp->room, tab[1]))
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
		return (1);
	return (0);
}

int			add_connection(t_lem **lem, char **tab)
{
	int error;

	error = check_tub(*lem, tab);
	if (!ft_strequ(tab[0], tab[1]) && error == 0)
	{
		error += findroom_addtube(lem, tab[0], tab[1]);
		error += findroom_addtube(lem, tab[1], tab[0]);
	}
	else
		error += 1;
	return (error);
}
