/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:32:24 by arotondo          #+#    #+#             */
/*   Updated: 2024/09/03 16:02:09 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_tab(int **tab, t_env *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free (tab[i]);
		i++;
	}
	free (tab);
}
