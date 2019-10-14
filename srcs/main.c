/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:48:59 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/18 19:49:08 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	t_lem_in	lem_in;
	t_solution	solution;

	parser(&lem_in);
	solve(&lem_in, &solution);
	print_output(&lem_in, &solution);
	lem_free(&lem_in, &solution);
	return (0);
}
