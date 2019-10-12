/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:57:37 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/18 19:57:39 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		resolve_initialization(t_solution *solution)
{
	solution->round = 0;
	solution->rounds = NULL;
}

/*
**	Добавляет ход в текущий раунд
*/

void		resolve_addmove(t_solution *solution, t_room *dst)
{
	t_round	*round;
	t_dlist	*new;
	t_move	*move;

	move = ft_memalloc(sizeof(t_move));
	move->id_route = solution->route;
	move->ant_id = dst->ant_id;
	move->dst = dst;
	new = ft_dlstnew(move, sizeof(t_move));
	round = (t_round*)solution->rounds->content;
	ft_dlstadd(&round->moves, new);
}

/*
** Чистка dlist решения
*/

void		resolve_free(t_solution *solution)
{
	ft_dlstdel(&solution->rounds, round_free);
}
