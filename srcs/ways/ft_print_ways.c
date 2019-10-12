/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:57:22 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/18 19:57:24 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Печатает указанный маршрут
*/

void		ft_print_ways(t_route *route)
{
	t_bool	rev;

	rev = route->rooms->gen.room->type == end;
	ft_printf("Route #%d (len=%d)\t", route->id_route, route->len);
	if (rev)
		ft_reverse_glist(&route->rooms);
	print_nodes(route->rooms);
	if (rev)
		ft_reverse_glist(&route->rooms);
}
