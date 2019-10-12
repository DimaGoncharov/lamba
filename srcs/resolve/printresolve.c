/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printresolve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:57:45 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/18 19:57:48 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_round(t_lem_in lem_in, t_round *round)
{
	t_dlist		*curr;
	t_move		*move;

	curr = ft_dlstfirst(round->moves);
	while (curr != NULL)
	{
		move = (t_move*)curr->content;
		if (lem_in.opt.print_route == true)
			ft_printf("R%d:L%d-%s", move->id_route, move->ant_id,
				move->dst->name);
		else
			ft_printf("L%d-%s", move->ant_id, move->dst->name);
		if ((curr = curr->prev) != NULL)
			ft_putchar(' ');
	}
	ft_putendl("");
}

void		print_solve(t_lem_in lem_in, t_solution *solution)
{
	t_dlist	*curr;

	curr = ft_dlstfirst(solution->rounds);
	while (curr != NULL)
	{
		print_round(lem_in, (t_round*)curr->content);
		curr = curr->prev;
	}
}
