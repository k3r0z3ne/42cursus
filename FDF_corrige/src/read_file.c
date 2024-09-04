/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:55:32 by arotondo          #+#    #+#             */
/*   Updated: 2024/09/03 13:03:02 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	count_wd(char *line, char sep)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (!line || !sep)
		return (1);
	while (line[i])
	{
		while (line[i] == sep && line[i] != '\0')
			i++;
		if (line[i])
			n++;
		while (line[i] != sep && line[i] != '\0')
			i++;
	}
	return (n);
}

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	line = NULL;
	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line != NULL)
	{
		free (line);
		line = get_next_line(fd);
		height++;
	}
	close (fd);
	return (height);
}

int	get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(file_name, O_RDONLY, 0);
	width = 0;
	line = get_next_line(fd);
	width = count_wd(line, ' ');
	free (line);
	close (fd);
	return (width);
}

void	fill_matrix(int *h_line, char *line)
{
	char	**tab;
	int		i;

	tab = ft_split(line, ' ');
	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		h_line[i] = ft_atoi(tab[i]);
		free (tab[i]);
		i++;
	}
	free (tab);
}

int	read_file(char *file_name, t_env *data)
{
	int		i;
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (2);
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->matrix = (int **)ft_calloc((data->height), sizeof(int *));
	if (!data->matrix)
		return (free_tab(data->matrix, data), 1);
	i = -1;
	while (++i < data->height)
	{
		data->matrix[i] = (int *)ft_calloc((data->width), sizeof(int));
		if (!(data->matrix[i]))
		{
			free_tab(data->matrix, data);
			return (close (fd), 1);
		}
	}
	fill_tab(i, fd, data);
	get_next_line(-1);
	return (close (fd), 0);
}
