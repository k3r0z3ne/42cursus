/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:14:05 by arotondo          #+#    #+#             */
/*   Updated: 2024/09/03 16:01:11 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_color(t_env *data)
{
	int	dz;

	dz = data->z1 - data->z;
	if ((dz <= 0) || (dz > data->z1))
		data->color = PURPLE;
	else
		data->color = PURPLE;
}
