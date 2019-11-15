/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:27:13 by amurtone          #+#    #+#             */
/*   Updated: 2019/11/15 15:46:03 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
/*
#define TX tetrimino->block[j].x
#define TX(a) (tetrimino->bock[a].y)*/
typedef struct s_tile
{
	//char value;
	int x;
	int y;
} t_tile;

typedef struct s_tetrimino
{
	t_tile block[4];
} t_tetr;
/*
t_tetr *tetrimino;

c_coords(str, &tetrimino)

TX = i % 5;
TX() = i / 5;
*/
int		v_matrix(char *str)
{
	int i;
	int	d;
	int h;
	
	i = 0;
	d = 0;
	h = 0;
	ft_putendl("starting v_matrix");
	if (str[i + 4] != '\n' && str[i + 9] != '\n' && str[i + 14] != '\n'
		&& str[i + 19] != '\n' && (str[i + 20] != '\n' || str[i + 20] != '\0' ))
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			d++;
		if (str[i] == '#')
			h++;
		i++;
	}
	if (d == 12 && h == 4)
		return (0);
	return (-1);
}

/*
**Validates tetriminos by counting adjacent blocks, a valid tetrimino
**of 4 blocks has either
**6 or 8 sides connecting to another block
*/

int			v_tetris(char *str)
{
	int i;
	int c;

	c = 0;
	i = 0;
	ft_putendl("v_tetris start");
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				c++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				c++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				c++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				c++;
		}
		i++;
	}
	if (c == 6 || c == 8)
		return (0);
	return (-1);
}

int			c_x_min(int *cords)
{
	int		x;
	int		i;

	i = 0;
	x = cords[0];
	while (cords[i])
	{
		if (i % 2 == 0)
			if (cords[i] < x)
				x = cords[i];
	   i++;	
	}
	return (x);
}

int			c_y_min(int *cords)
{
	int		y;
	int 	i;

	i = 0;
	y = cords[1];
	while (cords[i])
	{
		if (i % 2 != 0)
			if (cords[i] < y)
				y = cords[i];
		i++;
	}
	return (y);
}

int			*c_adjusted(int *cords)
{
	int xmin;
	int ymin;
	int	i;
	
	i = 0;
	xmin = c_x_min(cords);
	ymin = c_y_min(cords);
	while (cords[i])
	{
		if (i % 2 == 0)
			cords[i] = cords[i] - xmin;
		else
			cords[i] = cords[i] - ymin;
		i++;	
	}
	return (cords);
}

int		c_tetris(char *str)
{
	int		count;
	int		i;

		i = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count / 5);
}

void	c_cords(char *str)
{
	//t_tile	h;
	t_tetr  tetri;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			tetri.block[j].x = i % 5;
			tetri.block[j].y = i / 5;
			ft_putnbr(tetri.block[j].x);
			ft_putnbr(tetri.block[j].y);
		}
		i++;
		j++;
	}
}

char	*v_file(char *argv)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	char	*str;
	int		ret;
	int 	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL); //error funktio
	ft_putendl("starting to read");
	if (!(str = ft_strnew(0)))
				return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_putendl(buf);
		if (v_tetris(buf) == 0 && v_matrix(buf) == 0)
		{
			ft_putendl("buf before strjoin");
			ft_putendl(buf);
			ft_putendl("starting str join");
			temp = ft_strjoin(str, buf);
			free(str);
			str = temp;
			ft_putendl("str after ft_strjoin");
			ft_putendl(str);
		}
		else
			return (NULL);
	}
	if (ret < 0)
		return (NULL);
	return (str);
}

int		main(int argc, char **argv)
{
	char	*s;
	int		c;

	if (argc > 1)
	{
		if (!(s = v_file(argv[1])))
		{
			ft_putendl("Error");
			return (0);
		}
		c = c_tetris(s);
		ft_putendl("String copied from file");
		ft_putendl(s);
	}
	// CLOSE !!
	return (0);
}
