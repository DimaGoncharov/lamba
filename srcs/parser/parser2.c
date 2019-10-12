/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:56:26 by ptorchbu          #+#    #+#             */
/*   Updated: 2019/09/21 16:05:58 by ptorchbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Разбирает указанную строку в число. Выход по ошибке.
*/

int		parse_string(char *s)
{
	int	i;
	int	res;
	int	mul;

	i = 0;
	if (s[i] == '-')
	{
		mul = -1;
		i++;
	}
	else
		mul = 1;
	res = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			lem_out();
		res *= 10;
		res += s[i] - '0';
		if (res < 0)
			lem_out();
		i++;
	}
	return (res * mul);
}

/*
**	Возвращает true,
**	если указанная строка содержит информацию о подключении к комнате.
*/

t_bool	parse_is_link(char *line)
{
	int	pos;
	int	len;

	len = ft_strlen(line);
	pos = ft_strindex(line, '-');
	if (pos == -1 || pos < 1 || pos >= len - 1)
		return (false);
	return (true);
}

/*
**	Разбирает и обрезает линию в 3 части: имя, координаты x и y.
**	После этого он создает комнату для списка комнат
**	Возвращает true, если указанная строка содержит информацию о комнате.
*/

void	parse_room(t_lem_in *lem_in, char *line, t_roomtype type)
{
	int		x;
	int		y;
	char	**tab;
	t_room	*new;

	if (((tab = ft_strsplit(line, ' ')) == NULL)
		|| tab[0] == NULL || (ft_strnequ(tab[0], "L", 1) == true)
		|| tab[1] == NULL
		|| tab[2] == NULL || tab[3] != NULL
		|| (ft_strlen(tab[1]) > MAX_NB_SIZE)
		|| (ft_strlen(tab[2]) > MAX_NB_SIZE))
	{
		ft_free_tab(&tab);
		lem_out();
	}
	x = parse_string(tab[1]);
	y = parse_string(tab[2]);
	new = create_newroom(tab[0], type, x, y);
	lem_addroom(lem_in, new);
	ft_free_tab(&tab);
}

/*
**	Создает связи между комнатами
*/

void	parse_link(t_lem_in *lem_in, char **line)
{
	char	*s1;
	char	*s2;
	int		pos;

	pos = ft_strindex(*line, '-');
	s1 = ft_strsub(*line, 0, pos);
	s2 = ft_strsub(*line, pos + 1, ft_strlen(*line) - pos);
	room_createlink(lem_in, s1, s2);
	free(s1);
	free(s2);
	ft_strdel(line);
}
