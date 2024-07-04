/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:17:41 by arotondo          #+#    #+#             */
/*   Updated: 2024/07/04 15:17:07 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	i = 1;
	printf("{line %d} : %s\n", i, line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
		printf("{line %d} : %s\n", i, line);
	}
	free (line);
	close (fd);
	return (0);
}

// int	main(void)
// {
// 	int		i;
// 	int		fd;
// 	char	*next_line;

// 	i = 0;
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (printf("Error opening file"));
// 	while (i < 20)
// 	{
// 		next_line = get_next_line(fd);
// 		printf("[%d]: %s\n", i, next_line);
// 		i++;
// 		next_line = NULL;
// 		free (next_line);
// 	}
// 	close(fd);
// 	return (0);
// }