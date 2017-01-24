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
	ft_putendl("tube0");
	while (tmp1 && !ft_strequ(tmp1->room, room))
	{
		ft_printf("room = %s\n",tmp1->room);
		tmp1 = tmp1->next;
	}
	ft_putendl("tube1");
	if (!tmp1)
		return (1);
	tmp2 = tmp1->lst;
	ft_putendl("tube2");
	while (tmp2 && !ft_strequ(tmp2->content, dest))
		tmp2 = tmp2->next;
	ft_putendl("tube3");
	if (!tmp2)
	{
		new = ft_lstnew(dest, sizeof(dest));
		ft_lstadd(&tmp1->lst, new); 
	}
	ft_putendl("tube4");
	return (0);
}

int			add_connection(t_lem **lem, char **tab)
{
	int error;

	error = 0;
	error += findroom_addtube(lem, tab[0], tab[1]);
	error += findroom_addtube(lem, tab[1], tab[0]);
	return (error);
}
