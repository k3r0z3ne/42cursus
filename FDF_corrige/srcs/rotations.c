/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:39:56 by arotondo          #+#    #+#             */
/*   Updated: 2024/09/02 11:04:01 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_z(env *data, points *cd)
{
	float	tmp;

	tmp = cd->x;
	cd->x = tmp * cos(data->gamma) - cd->y * sin(data->gamma);
	cd->y = tmp * sin(data->gamma) + cd->y * cos(data->gamma);
	tmp = cd->x1;
	cd->x1 = tmp * cos(data->gamma) - cd->y1 * sin(data->gamma);
	cd->y1 = tmp * sin(data->gamma) + cd->y1 * cos(data->gamma);
}

void	rotate_y(env *data, points *cd)
{
	float	tmp;

	tmp = cd->x;
	cd->x = tmp * cos(data->tetha) + data->z * sin(data->tetha);
	data->z = data->z * cos(data->tetha) - tmp * sin(data->tetha);
	tmp = cd->x1;
	cd->x1 = tmp * cos(data->tetha) + data->z1 * sin(data->tetha);
	data->z1 = data->z1 * cos(data->tetha) - tmp * sin(data->tetha);
}

void	rotate_x(env *data, points *cd)
{
	float	tmp;

	tmp = cd->y;
	cd->y = tmp * cos(data->alpha) - data->z * sin(data->alpha);
	data->z = tmp * sin(data->alpha) + data->z * cos(data->alpha);
	tmp = cd->y1;
	cd->y1 = tmp * cos(data->alpha) - data->z1 * sin(data->alpha);
	data->z1 = tmp * sin(data->alpha) + data->z1 * cos(data->alpha);
}

void	key_rotation(env *data, points *cd)
{
	rotate_x(data, cd);
	rotate_y(data, cd);
	rotate_z(data, cd);
}
