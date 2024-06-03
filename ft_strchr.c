/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:21:08 by arotondo          #+#    #+#             */
/*   Updated: 2024/05/24 15:40:03 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int to_find)
{
	while (*str != '\0')
	{
		if (*str == (char)to_find)
			return ((char *)str);
		str++;
	}
	if (*str == (char)to_find)
		return ((char *)str);
	return (NULL);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	printf("%s\n", ft_strchr(argv[1], *argv[2]));
	printf("%s\n", strchr(argv[1], *argv[2]));
	return (0);
}*/
