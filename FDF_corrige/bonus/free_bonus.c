/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:32:24 by arotondo          #+#    #+#             */
/*   Updated: 2024/09/04 13:28:26 by arotondo         ###   ########.fr       */
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

// void	free_tab2(int *tab, int len)
// {
// 	int	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		free (tab[i]);
// 		i++;
// 	}
// 	free (tab);
// }
