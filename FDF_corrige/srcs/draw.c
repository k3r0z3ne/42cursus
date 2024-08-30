/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:09:16 by arotondo          #+#    #+#             */
/*   Updated: 2024/08/30 18:55:58 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	bresenham(env *data)
{
	float	x_step;
	float	y_step;
	float	x_tmp;
	float	y_tmp;
	int		max;

	data->z = data->matrix[(int)data->y][(int)data->x];
	data->z1 = data->matrix[(int)data->y1][(int)data->x1];
	// printf("data->x1 = %f\n", data->x1);
	// printf("data->z = %f\n", data->z);
	// printf("data->z1 = %f\n", data->z1);
	x_tmp = data->x;
	y_tmp = data->y;
	select_color(data->z1, data);
	set_all(data);
	// key_rotation(data);
	x_step = data->x1 - data->x;
	y_step = data->y1 - data->y;
	// printf("x_step = %f\n", x_step);
	max = MAX(SIGN(x_step), SIGN(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x_tmp - data->x1) || (int)(y_tmp - data->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x_tmp, y_tmp, data->color);
		x_tmp += x_step;
		y_tmp += y_step;
	}
	// printf("x = %f\n", x);
	// printf("after pixel_put,,data->x = %f\n", data->x);
	// printf("after pixel_put,,data->x1 = %f\n", data->x1);
}

void	draw_line(env *data)
{
	// float	x;
	// float	y;

	data->y = 0;
	while (data->y < data->height)
	{
		printf("data->x = %f\n", data->x);
		printf("data->width = %d\n", data->width);
		data->x = 0;
		while (data->x < data->width)
		{
			if (data->x < data->width - 1)
			{
				data->x1 = data->x + 1;
				printf("data->x1 = %f\n", data->x1);
				bresenham(data);
			}
			if (data->y < data->height - 1)
			{
				data->y1 = data->y + 1;
				bresenham(data);
			}
			data->x++;
			// printf("after bresenham : %f\n", data->x);
		}
		data->y++;
	}
}
