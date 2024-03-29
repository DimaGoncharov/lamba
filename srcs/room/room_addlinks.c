/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_addlinks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:56:57 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/10/14 18:43:06 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Найти, если комната уже есть в списке связей
*/

static t_bool	room_copy_link(t_room *room, char *name)
{
	t_glist	*curr;

	if (room->links == NULL && room->links_count == 0)
		return (false);
	curr = room->links;
	while (curr)
	{
		if (ft_strequ(curr->gen.room->name, name))
			return (true);
		curr = curr->next;
	}
	return (false);
}

/*
**	Добавляет подключение комнаты к другой комнате,
**	используя имена комнат.
*/

void			room_createlink(t_lem_in *lem_in, char *origin, char *target)
{
	t_room	*origin_room;
	t_room	*target_room;
	t_glist	*new_o;
	t_glist	*new_t;

	origin_room = search_room(lem_in, origin);
	target_room = search_room(lem_in, target);
	if (room_copy_link(origin_room, target) == false)
	{
		new_t = ft_new_glist(target_room, sizeof(t_room));
		ft_add_glist(&origin_room->links, new_t);
		origin_room->links_count++;
		new_o = ft_new_glist(origin_room, sizeof(t_room));
		ft_add_glist(&target_room->links, new_o);
		target_room->links_count++;
	}
}

/*
**	Удаляет указанную ссылку из комнаты.
*/

void			room_deletelink(t_room *room, t_room *link)
{
	t_glist	**curr;

	curr = &room->links;
	while (*curr != NULL)
	{
		if ((*curr)->gen.room == link)
		{
			ft_delone_glist(curr, NULL);
			room->links_count--;
			return ;
		}
		curr = &(*curr)->next;
	}
}
