/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:30:44 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/09 10:24:41 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	check_int(char *str, int sgn)
{
	int i;

	i = 0;
	while (str[i] < '0' || str[i] > '9')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i == 10 && sgn == 1)
		if (ft_strcmp(str, "2147483647") > 0)
			return (0);
	if (i == 10 && sgn == -1)
		if (ft_strcmp(str, "2147483648") > 0)
			return (0);
	if (i > 10)
		return (0);
	return (1);
}

int			ft_atoi_checker(char *str, int *error)
{
	int i;
	int sgn;
	int res;

	res = 0;
	i = 0;
	sgn = 1;
	if (str[i] == '-')
		sgn = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	if (str[i] || !check_int(str, sgn))
		*error += 1;
	return (res * sgn);
}
