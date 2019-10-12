/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_glist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:53:42 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/18 19:53:47 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Возвращает копию всех элементов списка.
**	Копирует указатели контента.
**	Вывод в обратном порядке (как того требует route_creator).
*/

t_glist		*ft_copy_glist(t_glist *src)
{
	t_glist	*res;
	t_glist	*curr;
	t_glist	*new;

	res = NULL;
	curr = src;
	while (curr != NULL)
	{
		new = ft_new_glist(curr->gen.content, curr->content_size);
		ft_add_glist(&res, new);
		curr = curr->next;
	}
	return (res);
}
