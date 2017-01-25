/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_tube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:04:12 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/24 11:30:36 by fpipart          ###   ########.fr       */
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
		new = ft_lstnew(dest, sizeof(dest));
		ft_lstadd(&tmp1->lst, new); 
	}
	return (0);
}

int			add_connection(t_lem **lem, char **tab)
{
	int error;

	error = 0;
	if (!ft_strequ(tab[0], tab[1]))
	{
		error += findroom_addtube(lem, tab[0], tab[1]);
		error += findroom_addtube(lem, tab[1], tab[0]);
	}
	return (error);
}

void		print_res(t_lem *lem)
{
	t_lem	*tmp;
	t_list	*lst;

	tmp = lem;
	while (tmp)
	{
		ft_putendl("Room");
		ft_putendl(tmp->room);
		lst = tmp->lst;
		ft_putendl("List of the tube");
		while (lst)
		{
			ft_putendl(lst->content);
			lst = lst->next;
		}
		tmp = tmp->next;
	}
}
