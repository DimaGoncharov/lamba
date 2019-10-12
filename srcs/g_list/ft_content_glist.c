/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_glist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:19:15 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/21 16:09:20 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Возвращает true, если указанный указатель
**	присутствует в одном из содержимого узла.
*/

t_bool	ft_content_glist(t_glist *lst, void *content)
{
	t_glist	*curr;

	curr = lst;
	while (curr != NULL)
	{
		if (curr->gen.content == content)
			return (true);
		curr = curr->next;
	}
	return (false);
}
