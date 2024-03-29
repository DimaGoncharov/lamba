/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_bft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:52:53 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/10/14 18:32:58 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree	*tree_new(t_lem_in *lem_in)
{
	t_tree			*res;
	static int		id;

	(void)lem_in;
	res = ft_memalloc(sizeof(t_tree));
	id++;
	return (res);
}

/*
**	Удаляет указанный элемент дерева и его родителей,
**	если дочерний элемент отсутствует.
*/

void	tree_del(t_lem_in *lem_in, t_tree *tree)
{
	t_tree	*del;
	t_tree	*curr;

	(void)lem_in;
	curr = tree;
	while (curr != NULL && curr->child_count == 0)
	{
		del = curr;
		if (curr->parent != NULL)
			curr->parent->child_count--;
		curr = curr->parent;
		free(del);
	}
}

t_tree	*tree_create_child(t_lem_in *lem_in, t_tree *parent, t_room *room)
{
	t_tree	*res;

	(void)lem_in;
	res = tree_new(lem_in);
	res->parent = parent;
	res->intersection = parent->intersection;
	res->augmentation = parent->augmentation;
	res->room = room;
	if (parent != NULL)
		parent->child_count++;
	return (res);
}

t_route	*tree_to_route(t_tree *tree)
{
	t_tree	*curr;
	t_route	*res;

	res = route_new();
	curr = tree;
	while (curr != NULL)
	{
		route_add_node(res, curr->room);
		curr = curr->parent;
	}
	return (res);
}
