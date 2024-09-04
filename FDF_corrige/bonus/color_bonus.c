/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:14:05 by arotondo          #+#    #+#             */
/*   Updated: 2024/09/04 17:07:38 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_color(t_env *data)
{
	data->color[0] = WHITE;
	data->color[1] = RED;
	data->color[2] = GREEN;
	data->color[3] = BLUE;
	data->color[4] = PURPLE;
	data->color[5] = PINK;
	data->color[6] = YELLOW;
}

void	change_color(int key, t_env *data)
{
	if (key == 99)
	{
		data->curr_color++;
		if (data->curr_color > 6)
			data->curr_color = 0;
	}
	if (key == 102)
	{
		data->curr_color--;
		if (data->curr_color < 0)
		data->curr_color = 6;
	}
}
