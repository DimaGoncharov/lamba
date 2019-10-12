/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:56:04 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/18 19:56:06 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Главная функция парсинга
*/

void	parser(t_lem_in *lem_in)
{
	char *line;

	line = NULL;
	parse_ants(lem_in, &line);
	parse_rooms(lem_in, &line);
	lem_in->array_room = (t_room**)glist_inarray(lem_in->rooms);
	array_sort((void **)lem_in->array_room, lem_in->room_count, room_sort);
	parser_links(lem_in, &line);
	lem_in->start->ants = lem_in->total_ants;
	parse_optimizer(lem_in);
	ft_strdel(&line);
}
