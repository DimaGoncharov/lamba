/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_glist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:54:40 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/10/14 18:37:37 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_glist	*ft_new_glist(void const *content, size_t content_size)
{
	t_glist	*result;

	result = ft_memalloc(sizeof(t_glist));
	result->gen.content = (void*)content;
	if (content == NULL)
	{
		result->content_size = 0;
	}
	else
	{
		result->content_size = content_size;
	}
	result->next = NULL;
	return (result);
}

/*
**	Разворачивает указанный список
*/

void	ft_reverse_glist(t_glist **list)
{
	t_glist	*curr;
	t_glist	*prev;
	t_glist	*next;

	curr = *list;
	prev = 0;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*list = prev;
}

int		ft_length_glist(t_glist *list)
{
	t_glist	*curr;
	int		i;

	i = 0;
	curr = list;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
