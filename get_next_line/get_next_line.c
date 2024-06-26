/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:10:58 by arotondo          #+#    #+#             */
/*   Updated: 2024/06/26 16:37:23 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//size_t read(int fd, void *buf, size_t count);

#include "get_next_line.h"

static char	*set_line(char *buffer_line)
{
	static char	*line;
	size_t		len;

	line = NULL;
	len = ft_strlen(buffer_line) + ft_strlen(line);
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (NULL);
	line = ft_strjoin(line, buffer_line);
	free (buffer_line);
	return (line);
}

static char	*read_line(int fd, char *buffer)
{
	ssize_t	bytes_read;
	ssize_t	i;
	char	*buffer_line;
	char 	*rest;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	i = 0;
	rest = NULL;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
			rest = buffer + i;
		if (rest)
		{
			buffer_line = ft_substr(rest, i, (bytes_read - i));
			return (set_line(buffer_line));
		}
		i++;
	}
	buffer_line = (char *)malloc(sizeof(char) * bytes_read + 1);
	if (!buffer_line)
		return (NULL);
	buffer_line = ft_strdup(buffer);
	return (set_line(buffer_line));
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer);
	return (line);
}
