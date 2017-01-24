/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:09:05 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/24 17:09:00 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	del_tube(t_list **lst)
{
	t_list *lst1;
	t_list *lst2;

	lst1 = *lst;
	while (lst1)
	{
		ft_putendl("123");
		lst2 = lst1->next;
		free(lst1->content);
		free(lst1);
		lst1 = lst2;
	}
	*lst = NULL;
}

static int	del_tube_each_room(t_lem **lem)
{
	t_lem	*tmp;

	if (lem)
	{
		tmp = *lem;
		while (tmp)
		{
			del_tube(&tmp->lst);
			tmp = tmp->next;
		}
	}
	return (0);
}

static int	del_lem(t_lem **lst)
{
	t_lem *lst1;
	t_lem *lst2;

	lst1 = *lst;
	while (lst1->next)
	{
		ft_putendl("456");
		lst2 = lst1->next;
//		free(&lst1->crd_x);
//		free(&lst1->crd_y);
		free(&lst1->room);
//		free(&lst1);
		lst1 = lst2;
	}
	*lst = NULL;
	return (0);
}

void	del_lst(t_lem **lem, t_lem **cmd)
{
	t_lem *tmp;

	(void)cmd;
	tmp = *lem;
	del_tube_each_room(lem);
	del_lem(lem);
//	del_lem(cmd);
}
