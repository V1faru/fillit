/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:27:13 by amurtone          #+#    #+#             */
/*   Updated: 2019/11/21 11:59:55 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		v_matrix(char *str)
{
	int i;
	int	d;
	int h;

	i = 0;
	d = 0;
	h = 0;
	if (str[i + 4] != '\n' && str[i + 9] != '\n' && str[i + 14] != '\n'
			&& str[i + 19] != '\n' && (str[i + 20] != '\n' ||
				str[i + 20] != '\0'))
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

int		v_tetris(char *str)
{
	int i;
	int c;

	c = 0;
	i = 0;
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

int		v_xcases(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (str[len - 1] == '\n' && str[len - 2] == '\n')
		return (-1);
	return (0);
}

char	*v_file(char *argv)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	char	*str;
	int		ret;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1 || (!(str = ft_strnew(0))))
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (v_tetris(buf) == 0 && v_matrix(buf) == 0)
		{
			if (!(temp = ft_strjoin(str, buf)))
				return (NULL);
			free(str);
			str = temp;
		}
		else
			return (NULL);
	}
	if (ret < 0)
		return (NULL);
	return (str);
}
