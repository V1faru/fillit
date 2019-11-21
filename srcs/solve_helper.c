/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:48:01 by amurtone          #+#    #+#             */
/*   Updated: 2019/11/20 18:05:38 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr		zero_x(t_tetr *tetrimino)
{
	int	xmin;
	int	i;

	i = 0;
	xmin = c_x_min(tetrimino);
	while (i < 4)
	{
		tetrimino->block[i].x = tetrimino->block[i].x - xmin;
		i++;
	}
	return (*tetrimino);
}

t_tetr		shift_x(t_tetr *tetrimino)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tetrimino->block[i].x = tetrimino->block[i].x + 1;
		i++;
	}
	return (*tetrimino);
}

t_tetr		shift_y(t_tetr *tetrimino)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tetrimino->block[i].y = tetrimino->block[i].y + 1;
		i++;
	}
	return (*tetrimino);
}

void		place_block(t_map *map, t_tetr *tetrimino, char character)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i < 4)
	{
		x = tetrimino->block[i].x;
		y = tetrimino->block[i].y;
		map->grid[y][x] = character;
		i++;
	}
}
