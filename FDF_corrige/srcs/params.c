/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:20:21 by arotondo          #+#    #+#             */
/*   Updated: 2024/08/25 18:14:55 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set(env *data)
{
	data->x = 0;
	data->y = 0;
	data->x1 = 0;
	data->y1 = 0;
	data->scale = 40;
	data->z_scale = data->scale / 3;
	data->win_x = 1920 / 2;
	data->win_y = 1080;
	data->angle = 0.8;
	data->shift_x = data->win_x / 3;
	data->shift_y = data->win_y / 3;
	data->alpha = 0;
	data->gamma = 0;
	data->tetha = 0;
}

void	zoom(env *data)
{
	data->x *= data->scale;
	printf("zoom, x = %f\n", data->x);
	data->x1 *= data->scale;
	printf("zoom, x1 = %f\n", data->x1);
	data->y *= data->scale;
	printf("zoom, y = %f\n", data->y);
	data->y1 *= data->scale;
	printf("zoom, y1 = %f\n", data->y1);
}

void	zzoom(env *data)
{
	data->z *= data->z_scale;
	data->z1 *= data->z_scale;
}

void	focus(env *data)
{
	data->x += data->shift_x;
	data->x1 += data->shift_x;
	data->y += data->shift_y;
	data->y1 += data->shift_y;
}

void	set_all(env *data)
{
	zoom(data);
	zzoom(data);
	isometric(data);
	isometric1(data);
	// focus(data);
}
