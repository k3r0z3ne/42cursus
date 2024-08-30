/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:14:05 by arotondo          #+#    #+#             */
/*   Updated: 2024/08/08 19:05:10 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	select_color(float z1, env *data)
{
	int	dx;
	int	dy;

	dx = data->x1 - data->x;
	dy = data->y1 - data->y;
	if (data->z == 0 || data->z < z1)
		data->color = YELLOW;
	if (data->z > 0 || z1 > 0)
		data->color = PINK;
	if (data->z < 0 || z1 < 0)
		data->color = RED;
	if (dx > 0)
		data->color = RED;
}
