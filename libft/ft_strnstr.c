/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:23:24 by arotondo          #+#    #+#             */
/*   Updated: 2024/05/27 20:10:25 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	x;
	size_t	y;
	size_t	to_find_len;

	x = 0;
	if (*to_find == '\0')
		return ((char *)(str));
	to_find_len = ft_strlen(to_find);
	while (str[x] != '\0' && x < size)
	{
		y = 0;
		while (str[x + y] == to_find[y] && (x + y) < size)
		{
			if (to_find[y + 1] == '\0')
				return ((char *)(str + x));
			y++;
		}
		x++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	test1[5] = "AAAAA";
	char	to_find1[5] = "AAAAA";
	char	test2[18] = "MZIRIBMZIRIBMZE123";
	char	to_find2[9] = "MZIRIBMZE";

	printf("test 1 = %s\n", ft_strnstr(test1, to_find1, ft_strlen(to_find1)));
	printf("test 2 = %s\n", ft_strnstr(test2, to_find2, ft_strlen(to_find2)));
	return (0);
}*/
