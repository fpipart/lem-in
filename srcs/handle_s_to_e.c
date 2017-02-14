/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s_to_e.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:52:52 by fpipart           #+#    #+#             */
/*   Updated: 2017/02/14 13:57:17 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		move_ant_s_to_e(t_store *store)
{
	print_ant_position(ft_itoa(store->ants), store->end);
	store->ants_strt--;
	store->ants_end++;
	store->ants++;
	return (0);
}
