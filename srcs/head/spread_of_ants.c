/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spread_of_ants.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:55:35 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/21 16:07:17 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Возвращает количество раундов,
**	необходимое после добавления одного дополнительного муравья.
*/

static int	rounds_for_route(t_group *group, int index)
{
	int	new_ants_count;

	new_ants_count = group->ants_distribution[index] + 1;
	return (group->routes[index]->len + new_ants_count - 1);
}

static void	distribute_one(t_group *group)
{
	int	i;

	i = 0;
	while (i < group->route_count - 1
		&& rounds_for_route(group, i) >= rounds_for_route(group, i + 1))
	{
		i++;
	}
	group->ants_distribution[i]++;
}

/*
**	Хранит и выстраивает количество муравьв,
**	которые будут перемещаться по маршрутам
*/

void		spread_ants(t_group *group, int total_ants)
{
	int	left_ants;

	left_ants = total_ants;
	while (left_ants > 0)
	{
		distribute_one(group);
		left_ants--;
	}
}
