/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desicion.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:59:16 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/21 17:30:11 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Запускает обход Эдмондса-Карпа как можно чаще и
**	каждый раз записывает группу маршрутов
*/

static t_group	*create_best_group(t_lem_in *lem_in)
{
	t_group			*best_group;
	t_group			*group;
	int				count;
	t_route			*traverse;

	count = 0;
	best_group = NULL;
	while (count < lem_in->max_routes && (traverse = start_bfs(lem_in)) != NULL)
	{
		rebuild_ways(lem_in, traverse);
		group = class_create(lem_in);
		route_free(traverse, sizeof(t_route));
		if (best_group == NULL)
			best_group = group;
		else if (best_group->total_rounds > group->total_rounds)
		{
			class_free(best_group, sizeof(t_group));
			best_group = group;
		}
		else
			class_free(group, sizeof(t_group));
		count++;
	}
	return (best_group);
}

/*
**	Основная функция решения проблем
**	Выбирает лучшую группу и печатает решение
*/

void			solve(t_lem_in *lem_in, t_solution *solution)
{
	t_group		*best_group;

	lem_in->max_routes = max_routes(lem_in);
	best_group = create_best_group(lem_in);
	if (best_group == NULL || best_group->routes == NULL)
		lem_out();
	create_solve(lem_in, best_group, solution);
	class_free(best_group, sizeof(t_group));
}
