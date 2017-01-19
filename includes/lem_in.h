/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:05:04 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/19 18:55:38 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/libft.h"
#include <stdlib.h>

typedef struct			s_lem
{
		char			*room;
		int				coord_x;
		int				coord_y;
		int				dest;
		struct s_list	*lst;
		struct s_lem	*next;
}						t_lem;

typedef struct			s_store
{
		int				nbr_a;
		int				nbr_rm;
		int				tube;
}						t_store;


#endif
