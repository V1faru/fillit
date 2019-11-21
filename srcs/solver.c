/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:50:22 by amurtone          #+#    #+#             */
/*   Updated: 2019/11/20 17:57:05 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			overlap(t_map *map, t_tetr *tetrimino)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = tetrimino->block[i].x;
	y = tetrimino->block[i].y;
	while (i < 4)
	{
		if (map->grid[y][x] != '.')
			return (1);
		i++;
		x = tetrimino->block[i].x;
		y = tetrimino->block[i].y;
	}
	return (0);
}

int			in_bounds(t_tetr *tetrimino, int size, char axis)
{
	if (axis == 'y')
		return (tetrimino->block[0].y < size && tetrimino->block[1].y < size &&
				tetrimino->block[2].y < size && tetrimino->block[3].y < size);
	else
		return (tetrimino->block[0].x < size && tetrimino->block[1].x < size &&
				tetrimino->block[2].x < size && tetrimino->block[3].x < size);
}

int			solve_blocks(t_map *map, t_tetr **tetrimino, int sz, int i)
{
	if (tetrimino[i] == NULL)
		return (1);
	c_adjusted(tetrimino[i]);
	while (in_bounds(tetrimino[i], sz, 'y'))
	{
		while (in_bounds(tetrimino[i], sz, 'x'))
		{
			if (overlap(map, tetrimino[i]) == 0)
			{
				place_block(map, tetrimino[i], tetrimino[i]->value);
				i++;
				if (solve_blocks(map, tetrimino, sz, i))
					return (1);
				else
				{
					i--;
					place_block(map, tetrimino[i], '.');
				}
			}
			shift_x(tetrimino[i]);
		}
		zero_x(tetrimino[i]);
		shift_y(tetrimino[i]);
	}
	return (0);
}

void		solve(t_tetr **tetrimino, char *str)
{
	t_map	*map;
	int		min;

	min = min_sqr(c_tetris(str));
	map = gen_map(min);
	while (!solve_blocks(map, tetrimino, min, 0))
	{
		free_map(map, min);
		min++;
		map = gen_map(min);
	}
	print_map(map, min);
	free_map(map, min);
}
