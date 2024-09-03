/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:00:02 by arotondo          #+#    #+#             */
/*   Updated: 2024/09/03 16:01:51 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	init_pointers(t_env *data)
{
	data->mlx_ptr = NULL;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = NULL;
	data->win_ptr = \
	mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, "FDF");
	if (!data->win_ptr)
		return (free (data->mlx_ptr), 2);
	return (0);
}

void	fill_tab(int i, int fd, t_env *data)
{
	char	*line;

	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		fill_matrix(data->matrix[i], line);
		if (!(&fill_matrix))
			break ;
		free (line);
		i++;
	}
}

int	close_win(t_env *data)
{
	mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env		data;

	if (argc != 2)
		return (strerror(errno), 2);
	if (read_file(argv[1], &data) != 0)
		return (1);
	set(&data);
	if (init_pointers(&data) != 0)
	{
		free_tab(data.matrix, &data);
		return (1);
	}
	draw_line(&data);
	mlx_key_hook(data.win_ptr, key_dealer, &data);
	mlx_hook(data.win_ptr, 17, 0, close_win, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free_tab(data.matrix, &data);
	free (data.mlx_ptr);
	return (0);
}
