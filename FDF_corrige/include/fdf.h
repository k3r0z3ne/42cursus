/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:20:11 by arotondo          #+#    #+#             */
/*   Updated: 2024/08/29 17:59:12 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PURPLE 0x6600FF
# define YELLOW 0xFFFF00
# define PINK 0xFF00FF

# define MAX(x, y) (x > y ? x : y)
# define SIGN(x) (x < 0 ? -x : x)

#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct
{
	float	x;
	float	y;
	float	z;
	float	x1;
	float	y1;
	float	z1;

	int	height;
	int	width;
	int	color;
	int	scale;
	int	z_scale;
	int	shift_x;
	int	shift_y;
	int	win_x;
	int	win_y;
	int	**matrix;

	double	alpha;
	double	gamma;
	double	tetha;
	double	angle;

	void	*mlx_ptr;
	void	*win_ptr;
}			env;

int	init_pointers(env *data);
int	close_win(env *data);
int	main(int argc, char **argv);

void	fill_tab(int i, int fd, env *data);
void	read_file(char *file_name, env *data);
void	fill_matrix(int *h_line, char *line);
int	get_width(char *file_name);
int	get_height(char *file_name);
int	count_wd(char *line, char sep);

void	bresenham(env *data);
void	draw_line(env *data);

void	set(env *data);
void	zoom(env *data);
void	zzoom(env *data);
void	focus(env *data);
void	set_all(env *data);

void	select_color(float z1, env *data);

void	isometric(env *data);
void	isometric1(env *data);
void	orthographic(env *data);

int	key_dealer(int key, env *data);
int	is_key(int key);
void	do_key(int key, env *data);
void	rotate(int key, env *data);

void	key_rotation(env *data);
void	rotate_x(env *data);
void	rotate_y(env *data);
void	rotate_z(env *data);

void	free_tab(int **tab, env *data);

#endif