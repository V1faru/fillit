/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:10:18 by amurtone          #+#    #+#             */
/*   Updated: 2019/11/21 11:55:25 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*s;
	t_tetr	**tetrimino;
	int		c;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit sample_file");
		return (1);
	}
	if (!(s = v_file(argv[1])) || v_xcases(s) != 0 ||
			(c = c_tetris(s)) > 25 || s[0] == '\0')
	{
		ft_putendl("error");
		return (0);
	}
	if (!(tetrimino = (t_tetr**)malloc(sizeof(t_tetr *) * 27)))
		return (-1);
	c_cords(s, tetrimino);
	solve(tetrimino, s);
	return (0);
}
