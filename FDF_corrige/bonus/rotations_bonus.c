/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:39:56 by arotondo          #+#    #+#             */
/*   Updated: 2024/09/03 16:03:03 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_z(t_env *data, t_points *cd)
{
	cd->x = cd->x * cos(data->gamma) - cd->y * sin(data->gamma);
	cd->y = cd->x * sin(data->gamma) + cd->y * cos(data->gamma);
	cd->x1 = cd->x1 * cos(data->gamma) - cd->y1 * sin(data->gamma);
	cd->y1 = cd->x1 * sin(data->gamma) + cd->y1 * cos(data->gamma);
}

void	rotate_y(t_env *data, t_points *cd)
{
	cd->x = cd->x * cos(data->tetha) + data->z * sin(data->tetha);
	data->z = data->z * cos(data->tetha) - cd->x * sin(data->tetha);
	cd->x1 = cd->x1 * cos(data->tetha) + data->z1 * sin(data->tetha);
	data->z1 = data->z1 * cos(data->tetha) - cd->x1 * sin(data->tetha);
}

void	rotate_x(t_env *data, t_points *cd)
{
	cd->y = cd->y * cos(data->alpha) - data->z * sin(data->alpha);
	data->z = cd->y * sin(data->alpha) + data->z * cos(data->alpha);
	cd->y1 = cd->y1 * cos(data->alpha) - data->z1 * sin(data->alpha);
	data->z1 = cd->y1 * sin(data->alpha) + data->z1 * cos(data->alpha);
}

void	key_rotation(t_env *data, t_points *cd)
{
	rotate_x(data, cd);
	rotate_y(data, cd);
	rotate_z(data, cd);
}
