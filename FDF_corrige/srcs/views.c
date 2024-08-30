/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:01:10 by arotondo          #+#    #+#             */
/*   Updated: 2024/08/08 19:30:47 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	isometric(env *data)
{
	float	tmp;

	tmp = data->x;
	data->x = (tmp - data->y) * cos(data->angle);
	data->y = (tmp + data->y) * sin(data->angle) - data->z;
}

void	isometric1(env *data)
{
	float	tmp;

	tmp = data->x;
	data->x = (data->x - data->y) * cos(data->angle);
	data->y = (tmp + data->y) * sin(data->angle) - data->z1;
}
void	orthographic(env *data)
{
	data->angle = 0;
	data->x = (data->x - data->y) * cos(data->angle);
	data->y = (data->x + data->y) * sin(data->angle) - data->z;
}
