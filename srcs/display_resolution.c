/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:48:02 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/11 14:46:21 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			print_ant_position(char *ant, char *room)
{
	ft_printf("L%s-%s ", ant, room);
	return (0);
}

static int	sizeof_lst(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

//static void	print_tube(t_list *lst)
void	print_map(t_list *lst)
{
	t_list	*tmp;
	int		i;
	int		j;

	j = 0;
	i = sizeof_lst(lst);
	while (i > 0)
	{
		tmp = lst;
		j = 1;
		while (j < i)
		{
			tmp = tmp->next;
			j++;
		}
		i--;
		ft_printf("%s\n", tmp->content);
		tmp = NULL;
	}
	ft_putchar('\n');
}
/*
static int	sizeof_lem(t_lem *lem)
{
	int i;

	i = 0;
	while (lem)
	{
		lem = lem->next;
		i++;
	}
	return (i);
}

void		print_map(t_lem *lem, t_store *store, t_list *lst)
{
	t_lem	*tmp;
	int		i;
	int		j;

	ft_putnbr(store->ants);
	ft_putchar('\n');
	i = sizeof_lem(lem);
	while (i > 0)
	{
		tmp = lem;
		j = 1;
		while (j < i)
		{
			tmp = tmp->next;
			j++;
		}
		i--;
		if (ft_strequ(tmp->room, store->start))
			ft_putendl("##start");
		if (ft_strequ(tmp->room, store->end))
			ft_putendl("##end");
		ft_printf("%s %d %d\n", tmp->room, tmp->crd_x, tmp->crd_y);
	}
	print_tube(lst);
}*/
