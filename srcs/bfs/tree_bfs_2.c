/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_bft_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:53:02 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/18 19:53:05 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			tree_deletelist(t_lem_in *lem_in, t_glist **trees)
{
	while ((*trees) != NULL)
	{
		tree_del(lem_in, (*trees)->gen.tree);
		ft_delone_glist(trees, NULL);
	}
}
