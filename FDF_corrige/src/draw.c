/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:09:16 by arotondo          #+#    #+#             */
/*   Updated: 2024/09/04 16:32:47 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	ft_max(float x_step, float y_step)
{
	if (x_step > y_step)
		return (x_step);
	else
		return (y_step);
}

float	ft_sign(float step)
{
	if (step < 0)
		return (-step);
	else
		return (step);
}

void	bresenham(t_env *data, t_points cd)
{
	float	x_step;
	float	y_step;
	int		max;

	data->z = data->matrix[(int)cd.y][(int)cd.x];
	data->z1 = data->matrix[(int)cd.y1][(int)cd.x1];
	set_all(data, &cd);
	x_step = cd.x1 - cd.x;
	y_step = cd.y1 - cd.y;
	max = ft_max(ft_sign(x_step), ft_sign(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(cd.x - cd.x1) || (int)(cd.y - cd.y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, cd.x, cd.y, data->color[0]);
		cd.x += x_step;
		cd.y += y_step;
	}
}

void	init_tmp(t_points *cd_tmp, t_points cd)
{
	*cd_tmp = cd;
	cd_tmp->y1 = cd.y;
	cd_tmp->x1 = cd.x;
}

void	draw_line(t_env *data)
{
	t_points	cd;
	t_points	cd_tmp;

	cd.y = 0;
	while (cd.y < data->height)
	{
		cd.x = 0;
		while (cd.x < data->width)
		{
			if (cd.x < data->width - 1)
			{
				init_tmp(&cd_tmp, cd);
				cd_tmp.x1 = cd.x + 1;
				bresenham(data, cd_tmp);
			}
			if (cd.y < data->height - 1)
			{
				init_tmp(&cd_tmp, cd);
				cd_tmp.y1 = cd.y + 1;
				bresenham(data, cd_tmp);
			}
			cd.x++;
		}
		cd.y++;
	}
}
