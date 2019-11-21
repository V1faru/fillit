/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:27:53 by jwilen            #+#    #+#             */
/*   Updated: 2019/11/21 12:03:41 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../includes/libft/libft.h"

typedef	struct		s_tile
{
	int				x;
	int				y;
}					t_tile;

typedef	struct		s_tetrimino
{
	char			value;
	t_tile			block[4];
}					t_tetr;

typedef struct		s_map
{
	char			**grid;
}					t_map;

char				*v_file(char *argv);
int					v_matrix(char *str);
int					v_tetris(char *str);
int					c_tetris(char *str);
int					v_xcases(char *str);
int					assign_tile(t_tetr **tetrimino, int i, int k, int j);
int					c_x_min(t_tetr *tetri);
int					c_y_min(t_tetr *tetri);
int					min_sqr(int count);
int					overlap(t_map *map, t_tetr *tetrimino);
int					in_bounds(t_tetr *tetrimino, int size, char axis);
int					solve_blocks(t_map *map, t_tetr **tetrimino, int sz, int i);
void				print_map(t_map *map, int size);
void				free_map(t_map *map, int size);
void				c_cords(char *str, t_tetr **tetrimino);
void				place_block(t_map *map, t_tetr *tetrimino, char character);
void				solve(t_tetr **tetrimino, char *str);
t_tetr				c_adjusted(t_tetr *tetri);
t_tetr				zero_x(t_tetr *tetrimino);
t_tetr				shift_x(t_tetr *tetrimino);
t_tetr				shift_y(t_tetr *tetrimino);
t_map				*gen_map(int min);

#endif
