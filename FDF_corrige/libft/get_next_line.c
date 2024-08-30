/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:07:08 by arotondo          #+#    #+#             */
/*   Updated: 2024/08/02 21:37:09 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*next_line(char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*tmp;

	i = 0;
	len = ft_strlen(buffer);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	tmp = (char *)ft_calloc(sizeof(char), len - i + 1);
	if (!tmp)
		return (NULL);
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i + j] != '\0')
	{
		tmp[j] = buffer[i + j];
		j++;
	}
	return (free (buffer), tmp);
}

char	*set_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = (char *)ft_calloc(sizeof(char), i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*read_line(int fd, char *buffer)
{
	char	*tmp;
	ssize_t	bytes_read;

	if (buffer == NULL)
	{
		buffer = (char *)ft_calloc(sizeof(char), 1);
		if (!buffer)
			return (NULL);
	}
	tmp = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && (!ft_strchr(buffer, '\n')))
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free (buffer), free(tmp), NULL);
		tmp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (!buffer)
			break ;
	}
	return (free (tmp), buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stat_buffer;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
	{
		free(stat_buffer);
		stat_buffer = NULL;
		return (NULL);
	}
	stat_buffer = read_line(fd, stat_buffer);
	if (!stat_buffer)
		return (NULL);
	line = set_line(stat_buffer);
	if (!line || line[0] == '\0')
	{
		free (stat_buffer);
		stat_buffer = NULL;
		return (NULL);
	}
	stat_buffer = next_line(stat_buffer);
	if (stat_buffer == NULL)
		free (stat_buffer);
	return (line);
}
