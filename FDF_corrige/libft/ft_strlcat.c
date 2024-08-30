/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:13:55 by arotondo          #+#    #+#             */
/*   Updated: 2024/06/03 14:40:24 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(const char *dest, const char *src, size_t size)
{
	size_t			destlen;
	size_t			srclen;
	size_t			i;
	unsigned char	*conv_dest;
	unsigned char	*conv_src;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	conv_dest = (unsigned char *)dest;
	conv_src = (unsigned char *)src;
	i = 0;
	if (size <= destlen || size == 0)
		return (srclen + size);
	while (conv_src[i] != '\0' && (destlen + i + 1) < size)
	{
		conv_dest[destlen + i] = src[i];
		i++;
	}
	conv_dest[destlen + i] = '\0';
	return (srclen + destlen);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	printf("%d\n", ft_strlcat(argv[1], argv[2], atoi(argv[3])));
	return (0);
}*/
