/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:06:49 by amurtone          #+#    #+#             */
/*   Updated: 2019/11/21 11:58:29 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			c_x_min(t_tetr *tetri)
{
	int		x;
	int		i;

	i = 0;
	x = tetri->block[i].x;
	while (i < 4)
	{
		if (tetri->block[i].x < x)
		{
			x = tetri->block[i].x;
		}
		i++;
	}
	return (x);
}

int			c_y_min(t_tetr *tetri)
{
	int		y;
	int		i;

	i = 0;
	y = tetri->block[i].y;
	while (i < 4)
	{
		if (tetri->block[i].y < y)
		{
			y = tetri->block[i].y;
		}
		i++;
	}
	return (y);
}

t_tetr		c_adjusted(t_tetr *tetri)
{
	int xmin;
	int ymin;
	int	i;

	i = 0;
	xmin = c_x_min(tetri);
	ymin = c_y_min(tetri);
	while (i < 4)
	{
		tetri->block[i].x = tetri->block[i].x - xmin;
		tetri->block[i].y = tetri->block[i].y - ymin;
		i++;
	}
	return (*tetri);
}

int			assign_tile(t_tetr **tetrimino, int i, int k, int j)
{
	tetrimino[k]->value = k + 65;
	tetrimino[k]->block[j].x = i % 5;
	tetrimino[k]->block[j].y = i / 5;
	j++;
	return (j);
}

void		c_cords(char *str, t_tetr **tetrimino)
{
	int		i;
	int		j;
	int		k;
	int		start;
	int		len;

	start = 0;
	k = 0;
	len = ft_strlen(str);
	while (start < len)
	{
		if (!(tetrimino[k] = (t_tetr*)malloc(sizeof(t_tetr))))
			return ;
		i = 0;
		j = 0;
		while (i < 21 && i + start < len)
		{
			if (str[i + start] == '#')
				j = assign_tile(tetrimino, i, k, j);
			i++;
		}
		start += i;
		k++;
	}
	tetrimino[k] = NULL;
}
