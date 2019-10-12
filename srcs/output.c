/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:48:42 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/18 19:48:47 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Сохраняет указанную строку без комментариев для отображения
*/

void	save_output(t_lem_in *lem_in, char *line)
{
	t_list *new;

	new = NULL;
	if (line)
	{
		new = ft_lstnew(ft_strdup(line), 1);
		ft_lstadd(&lem_in->display, new);
	}
}

/*
**	Печатает строку списка от конца до начала
*/

void	print_line(t_list *display)
{
	while (display && display->content != NULL)
	{
		ft_printf("%s\n", display->content);
		display = display->next;
	}
}

/*
**	Печать строк
*/

void	print_output(t_lem_in *lem_in)
{
	ft_lstrev(&lem_in->display);
	print_line(lem_in->display);
	ft_printf("\n");
}

/*
**	Чистка слхранненых линий
*/

void	free_output(t_lem_in *lem_in)
{
	ft_lst_del(&lem_in->display);
}
