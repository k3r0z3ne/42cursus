/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:38:57 by arotondo          #+#    #+#             */
/*   Updated: 2024/05/27 16:51:52 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			srclen;
	size_t			i;
	unsigned char	*conv_src;

	i = 0;
	srclen = ft_strlen(src);
	conv_src = (unsigned char *)src;
	while (conv_src[i] != '\0' && (i + 1) < size)
	{
		dest[i] = conv_src[i];
		i++;
	}
	if (size != '\0')
		dest[i] = '\0';
	return (srclen);
}
/*
int	main(void)
{
	char    destination[10];
	char    source[] = "Successssssssss";
	
	printf("ft_strlcpy : %zu\n", ft_strlcpy(destination, source, 20));
	return (0);
}*/
