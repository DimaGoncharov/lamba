/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:56:48 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/18 19:56:50 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Создает новую комнату
*/

t_room	*create_newroom(char *name, t_roomtype type, int x, int y)
{
	t_room		*res;
	static int	id;

	res = ft_memalloc(sizeof(t_room));
	res->id = id;
	res->name = ft_strdup(name);
	res->type = type;
	res->pos.x = x;
	res->pos.y = y;
	id++;
	return (res);
}

/*
**	Возвращает комнату с указанным именем.
*/

t_room	*search_room(t_lem_in *lem_in, char *name)
{
	int		pos;
	int		size;
	int		cmp;
	int		step;

	pos = (lem_in->room_count) / 2;
	size = (lem_in->room_count - 1);
	step = 0;
	while (pos >= 0 && pos <= size && step != pos)
	{
		if ((cmp = ft_strcmp(name, lem_in->array_room[pos]->name)) == 0)
			return ((t_room*)lem_in->array_room[pos]);
		else
		{
			if (cmp < 0)
			{
				step = pos;
				pos = (pos <= 1) ? (pos - 1) : (pos / 2);
			}
			else
				pos = (pos + 1);
		}
	}
	lem_out();
	return (NULL);
}

/*
**	Освобождает указанный объект комнаты и его элементы.
**	Использовать с ft_delete_glist()
*/

void	room_free(void *content, size_t size)
{
	t_room *room;

	(void)size;
	room = (t_room*)content;
	free(room->name);
	ft_delete_glist(&room->links, NULL);
	free(content);
}

/*
**	Сортировать по лексическому(алфавитному) порядку две комнаты.
*/

int		room_sort(void *a, void *b)
{
	t_room	*room_a;
	t_room	*room_b;
	int		cmp;

	room_a = (t_room*)a;
	room_b = (t_room*)b;
	if ((cmp = ft_strcmp(room_a->name, room_b->name)) == 0)
		lem_out();
	return (cmp);
}
