/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:48:02 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/14 14:13:44 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			print_ant_position(char *ant, char *room)
{
	int	c;

	if (ft_strequ(COLOR, "true"))
	{
		c = ft_atoi(ant);
		if (c > 6)
			c = 31 + (c % 6);
		else
			c = c + 31;
		ft_printf("L\x1B[%dm%s\x1B[0m-%s ", c, ant, room);
	}
	else
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
