/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ways.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:57:13 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/10/14 18:29:45 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Создает новый маршрут
*/

t_route		*route_new(void)
{
	t_route		*res;
	static int	id;

	res = ft_memalloc(sizeof(t_route));
	res->len = -1;
	res->id_route = id;
	id++;
	return (res);
}

/*
**	Создает новый маршрут от заголовка начального узла
**	до указанного второго узла
*/

t_route		*route_build(t_room *start, t_room *second)
{
	t_route	*res;
	t_room	*curr;

	res = route_new();
	route_add_node(res, start);
	curr = second;
	while (curr != NULL)
	{
		route_add_node(res, curr);
		curr = curr->next;
	}
	return (res);
}

/*
**	Дублирует указанный маршрут
*/

t_route		*route_copy(t_route *src)
{
	t_route	*res;

	res = route_new();
	res->len = src->len;
	res->rooms = ft_copy_glist(src->rooms);
	ft_reverse_glist(&res->rooms);
	return (res);
}

/*
**	Чистка элементов маршрута
*/

void		route_free(void *content, size_t size)
{
	t_route	*route;

	(void)size;
	route = (t_route*)content;
	ft_delete_glist(&route->rooms, NULL);
	free(route);
}

/*
**	Добавить новый элемент в маршрут
*/

void		route_add_node(t_route *route, t_room *room)
{
	t_glist	*new;

	new = ft_new_glist(room, sizeof(t_room));
	ft_add_glist(&route->rooms, new);
	route->len++;
}
