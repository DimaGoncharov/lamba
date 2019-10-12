/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_glist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:53:55 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/18 19:53:57 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_delete_glist(t_glist **alst, void (*del)(void *, size_t))
{
	t_glist	*curr;
	t_glist	*next;

	curr = *alst;
	while ((curr) != NULL)
	{
		next = (curr)->next;
		ft_delone_glist(&curr, del);
	}
	*alst = NULL;
}
