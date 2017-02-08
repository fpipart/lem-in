/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:54:09 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/08 17:26:06 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

static void	count_passage_room(t_list **lst, char *line)
{
	char	**tab;
	int		nbr;
	int		i;
	t_list	*tmp;

	i = 1;
	tab = ft_strsplit(line , ' ');
	nbr = ft_wordcount(line, ' ');
	tmp = *lst;
	while (i <= nbr)
	{
		if ((tab[i] + 1))
		i++;
	}
}

int main(int argc, char **argv)
{
	char *line;
	t_list *lst;
	int fd;

	if (argc > 1)
	{
		line = NULL;
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			count_passage_room(&lst, line);
		}
	}
}
