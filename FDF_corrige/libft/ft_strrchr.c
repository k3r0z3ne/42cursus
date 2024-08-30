/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:13:10 by arotondo          #+#    #+#             */
/*   Updated: 2024/06/06 12:52:19 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int to_find)
{
	size_t	i;

	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == (char)to_find)
			return ((char *)(str + i));
		i--;
	}
	if (str[0] == (char)to_find)
		return ((char *)(str));
	return (NULL);
}
/*
int	main(void)
{
	printf("%s\n", ft_strrchr("ltripuiel", 'l'));
	return (0);
}*/
/*
int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	printf("%s\n", ft_strrchr(argv[1], *argv[2]));
	printf("%s\n", strrchr(argv[1], *argv[2]));
	return (0);
}*/
