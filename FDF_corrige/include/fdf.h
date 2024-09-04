/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:20:11 by arotondo          #+#    #+#             */
/*   Updated: 2024/09/04 17:07:43 by arotondo         ###   ########.fr       */
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

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_env
{
	float	z;
	float	z1;
	int		height;
	int		width;
	int		color[7];
	int		curr_color;
	int		scale;
	int		shift_x;
	int		shift_y;
	int		win_x;
	int		win_y;
	int		**matrix;
	double	alpha;
	double	gamma;
	double	tetha;
	double	angle;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_env;

typedef struct s_points
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}			t_points;

int		init_pointers(t_env *data);
int		close_win(t_env *data);
int		main(int argc, char **argv);

void	fill_tab(int i, int fd, t_env *data);
void	fill_matrix(int *h_line, char *line);
int		read_file(char *file_name, t_env *data);
int		get_width(char *file_name);
int		get_height(char *file_name);
int		count_wd(char *line, char sep);

float	ft_max(float x_step, float y_step);
float	ft_sign(float step);
void	bresenham(t_env *data, t_points cd);
void	init_tmp(t_points *cd_tmp, t_points cd);
void	draw_line(t_env *data);

void	set(t_env *data);
void	zoom(t_env *data, t_points *cd);
void	focus(t_env *data, t_points *cd);
void	set_all(t_env *data, t_points *cd);

void	set_color(t_env *data);
void	change_color(int key, t_env *data);

void	isometric(float z, t_env *data, t_points *cd);
void	isometric1(float z1, t_env *data, t_points *cd);
void	orthographic(t_env *data, t_points *cd);

int		key_dealer(int key, t_env *data, t_points cd);
int		is_key(int key);
void	do_key(int key, t_env *data, t_points *cd);
void	rotate(int key, t_env *data);

void	key_rotation(t_env *data, t_points *cd);
void	rotate_x(t_env *data, t_points *cd);
void	rotate_y(t_env *data, t_points *cd);
void	rotate_z(t_env *data, t_points *cd);

void	free_tab(int **tab, t_env *data);
void	free_tab2(int *tab, int len);

#endif