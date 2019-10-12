/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_glist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:54:56 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/18 19:55:00 by ptorchbu         ###   ########.fr       */
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
