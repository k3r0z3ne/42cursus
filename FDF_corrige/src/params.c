/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:20:21 by arotondo          #+#    #+#             */
/*   Updated: 2024/09/04 13:39:51 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set(t_env *data)
{
	data->color[0] = WHITE;
	data->scale = 30;
	data->win_x = 1920 / 2;
	data->win_y = 1080;
	data->angle = 0.8;
	data->shift_x = data->win_x / 2.15;
	data->shift_y = data->win_y / 2;
	data->alpha = 0;
	data->gamma = 0;
	data->tetha = 0;
}

void	zoom(t_env *data, t_points *cd)
{
	cd->x *= data->scale;
	cd->x1 *= data->scale;
	cd->y *= data->scale;
	cd->y1 *= data->scale;
	data->z *= data->scale / 3;
	data->z1 *= data->scale / 3;
}

void	focus(t_env *data, t_points *cd)
{
	cd->x += data->shift_x;
	cd->x1 += data->shift_x;
	cd->y += data->shift_y;
	cd->y1 += data->shift_y;
}

void	set_all(t_env *data, t_points *cd)
{
	zoom(data, cd);
	isometric(data->z, data, cd);
	isometric1(data->z1, data, cd);
	focus(data, cd);
}
