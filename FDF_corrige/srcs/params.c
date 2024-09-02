/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:20:21 by arotondo          #+#    #+#             */
/*   Updated: 2024/09/02 15:17:32 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set(env *data)
{
	data->scale = 15;
	data->z_scale = data->scale / 3;
	data->win_x = 1920 / 2;
	data->win_y = 1080;
	data->angle = 0.5;
	data->shift_x = data->win_x / 3;
	data->shift_y = data->win_y / 3;
	data->alpha = 0;
	data->gamma = 0;
	data->tetha = 0;
}

void	zoom(env *data, points *cd)
{
	cd->x *= data->scale;
	cd->x1 *= data->scale;
	cd->y *= data->scale;
	cd->y1 *= data->scale;
	// data->z *= data->scale / 5;
	// data->z1 *= data->scale / 5;
}

void	zzoom(env *data)
{
	data->z *= data->z_scale;
	data->z1 *= data->z_scale;
}

void	focus(env *data, points *cd)
{
	cd->x += data->shift_x;
	cd->x1 += data->shift_x;
	cd->y += data->shift_y;
	cd->y1 += data->shift_y;
}

void	set_all(env *data, points *cd)
{
	zoom(data, cd);
	zzoom(data);
	isometric(data->z, data, cd);
	isometric1(data->z1, data, cd);
	focus(data, cd);
}
