/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:27:13 by amurtone          #+#    #+#             */
/*   Updated: 2019/11/13 14:45:15 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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

int		*c_cords(char *str)
{
	int		x;
	int		y;
	int		i;
	int		*cords;
	int		j;

	if (!(cords = (int *)malloc(sizeof(int) * 8)))
			return (-1);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			cords[j] = i % 5;
			cords[j + 1] = i / 5;
		}
		i++;
		j += 2;
	}
	printf("%d\n", cords);
	return (cords);
}

char		*v_file(char *argv, const int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	char	*str;
	int		ret;
	int		*cords;

	ft_putendl("starting to read");
	if (str == NULL)
		str = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = ft_strdup(buf);
		if (v_tetris(temp) == 0 && v_matrix(temp) == 0)
		{
			ft_putendl(temp);
			cords = c_cords(temp);
			ft_putendl("starting str join");
			str = ft_strjoin(str, temp);
			ft_strdel(&temp);
		}
		else
			return (0);
	}
	if (ret < 0)
		return (0);
	return (str);
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

int		main(int argc, char **argv)
{
	char	*s;
	int		c;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc > 1)
	{
		if (!(s = v_file(argv[1], fd)))
		{
			ft_putendl("Error");
			return (0);
		}
		c = c_tetris(s);
		ft_putnbr(c);
		ft_putchar('\n');
		ft_putendl("String copied from file");
		ft_putendl(s);
	}
	// CLOSE !!
	return (0);
}
