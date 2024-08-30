/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:39:56 by arotondo          #+#    #+#             */
/*   Updated: 2024/08/08 19:03:50 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_z(env *data)
{
	float	tmp;

	tmp = data->x;
	data->x = tmp * cos(data->gamma) - data->y * sin(data->gamma);
	data->y = tmp * sin(data->gamma) + data->y * cos(data->gamma);
	tmp = data->x1;
	data->x1 = tmp * cos(data->gamma) - data->y1 * sin(data->gamma);
	data->y1 = tmp * sin(data->gamma) + data->y1 * cos(data->gamma);
}

void	rotate_y(env *data)
{
	float	tmp;

	tmp = data->x;
	data->x = tmp * cos(data->tetha) + data->z * sin(data->tetha);
	data->z = data->z * cos(data->tetha) - tmp * sin(data->tetha);
	tmp = data->x1;
	data->x1 = tmp * cos(data->tetha) + data->z1 * sin(data->tetha);
	data->z1 = data->z1 * cos(data->tetha) - tmp * sin(data->tetha);
}

void	rotate_x(env *data)
{
	float	tmp;

	tmp = data->y;
	data->y = tmp * cos(data->alpha) - data->z * sin(data->alpha);
	data->z = tmp * sin(data->alpha) + data->z * cos(data->alpha);
	tmp = data->y1;
	data->y1 = tmp * cos(data->alpha) - data->z1 * sin(data->alpha);
	data->z1 = tmp * sin(data->alpha) + data->z1 * cos(data->alpha);
}

void	key_rotation(env *data)
{
	rotate_x(data);
	rotate_y(data);
	rotate_z(data);
}
