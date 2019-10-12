/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delone_glist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:54:05 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/18 19:54:07 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_delone_glist(t_glist **alst, void (*del)(void *, size_t))
{
	t_glist	*next;

	if (del != NULL)
		del((*alst)->gen.content, (*alst)->content_size);
	next = (*alst)->next;
	free(*alst);
	*alst = next;
}
