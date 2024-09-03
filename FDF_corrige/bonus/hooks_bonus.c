/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:04:29 by arotondo          #+#    #+#             */
/*   Updated: 2024/09/03 16:02:22 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	is_key(int key)
{
	return (key == 65361 || key == 65362 || key == 65363 || key == 65364 || \
	key == 65451 || key == 65453 || key == 110 || key == 120 || \
	key == 121 || key == 122 || key == 97 || key == 115 || key == 118);
}

void	do_key(int key, t_env *data, t_points *cd)
{
	if (key == 65361)
		data->shift_x -= 15;
	if (key == 65363)
		data->shift_x += 15;
	if (key == 65364)
		data->shift_y += 15;
	if (key == 65362)
		data->shift_y -= 15;
	if (key == 65451)
		data->scale += 3;
	if (key == 65453)
		data->scale -= 3;
	if (key == 97)
		data->angle += 0.1;
	if (key == 115)
		data->angle -= 0.1;
	if (key == 118)
		orthographic(data, cd);
}

void	rotate(int key, t_env *data)
{
	if (key == 120)
		data->alpha += 0.3;
	if (key == 121)
		data->tetha += 0.3;
	if (key == 122)
		data->gamma += 0.3;
}

int	key_dealer(int key, t_env *data, t_points cd)
{
	if (is_key(key))
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		do_key(key, data, &cd);
		draw_line(data);
	}
	if (key == 120 || key == 121 || key == 122)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		rotate(key, data);
		draw_line(data);
	}
	if (key == 110)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		set(data);
		draw_line(data);
	}
	if (key == 65307)
		mlx_loop_end(data->mlx_ptr);
	return (0);
}
