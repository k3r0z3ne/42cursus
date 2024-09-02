/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:14:05 by arotondo          #+#    #+#             */
/*   Updated: 2024/09/02 14:52:25 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// void	set_color(env *data, points *cd)
// {
// 	int	dx;
// 	int	dy;

// 	(void)cd;
// 	dx = cd->x1 - cd->x;
// 	dy = cd->y1 - cd->y;
// 	if (data->z1 == 0)
// 		data->color = WHITE;
// 	else
// 		data->color = RED;
// 	if (data->z == 0 || data->z < data->z1)
// 		data->color = YELLOW;
// 	if (data->z > 0 || data->z1 > 0)
// 		data->color = PINK;
// 	if (data->z < 0 || data->z1 < 0)
// 		data->color = RED;
// 	if (dx > 0)
// 		data->color = RED;
// }

void	set_color(env *data, points *cd)
{
	(void)cd;
	data->color = WHITE;
}
