/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_glist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:54:40 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/18 19:54:46 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_length_glist(t_glist *list)
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
