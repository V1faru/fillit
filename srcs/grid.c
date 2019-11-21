/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:11:38 by amurtone          #+#    #+#             */
/*   Updated: 2019/11/21 11:48:31 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			min_sqr(int count)
{
	int	min_s;

	count = count * 4;
	min_s = 1;
	while (min_s * min_s < count)
		min_s++;
	return (min_s);
}

void		print_map(t_map *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putendl(map->grid[i]);
		i++;
	}
}

t_map		*gen_map(int min_s)
{
	t_map	*map;
	int		i;

	i = 0;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->grid = (char **)malloc(sizeof(char*) * min_s)))
		return (NULL);
	while (i < min_s)
	{
		map->grid[i] = ft_strnew(min_s);
		ft_memset(map->grid[i], '.', min_s);
		i++;
	}
	return (map);
}

void		free_map(t_map *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void **)&(map->grid[i]));
		i++;
	}
	ft_memdel((void **)&(map->grid));
	ft_memdel((void **)&map);
}
