/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:01:10 by arotondo          #+#    #+#             */
/*   Updated: 2024/09/03 16:03:16 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	isometric(float z, t_env *data, t_points *cd)
{
	cd->x = (cd->x - cd->y) * cos(data->angle);
	cd->y = (cd->x + cd->y) * sin(data->angle) - z;
}

void	isometric1(float z1, t_env *data, t_points *cd)
{
	cd->x1 = (cd->x1 - cd->y1) * cos(data->angle);
	cd->y1 = (cd->x1 + cd->y1) * sin(data->angle) - z1;
}

void	orthographic(t_env *data, t_points *cd)
{
	data->angle = 0;
	cd->x = (cd->x - cd->y) * cos(data->angle);
	cd->y = (cd->x + cd->y) * sin(data->angle) - data->z;
}
