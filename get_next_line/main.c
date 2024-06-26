/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:17:41 by arotondo          #+#    #+#             */
/*   Updated: 2024/06/26 16:02:42 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		i;
	int		fd;
	char	*next_line;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (printf("Error opening file"));
	while (1)
	{
		next_line = get_next_line(fd);
		if (!next_line)
			break ;
		printf("[%d]: %s\n", i, next_line);
		i++;
		free (next_line);
		next_line = NULL;
	}
	close(fd);
	return (0);
}
