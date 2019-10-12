/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:59:22 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/18 19:59:24 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	min(int a, int b)
{
	return (a > b ? b : a);
}

/*
**	Возвращает количество максимально возможных маршрутов
**	Соответствует минимальному числу исходящих маршрутов
**	от начального и конечного узлов и количеству муравьев
*/

int			max_routes(t_lem_in *lem_in)
{
	int	res;
	int	start;
	int	end;

	start = lem_in->start->links_count;
	end = lem_in->end->links_count;
	res = min(start, end);
	res = min(res, lem_in->total_ants);
	return (res);
}
