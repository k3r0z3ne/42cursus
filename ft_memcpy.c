/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:11:51 by arotondo          #+#    #+#             */
/*   Updated: 2024/05/24 17:29:29 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*conv_dest;
	unsigned char	*conv_src;
	size_t			i;

	conv_dest = (unsigned char *)dest;
	conv_src = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		conv_dest[i] = conv_src[i];
		i++;
	}
	return (dest);
}
/*
void	foo(char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	char	src[5] = "abcde";
	char	dest[5] = "00000";

	ft_memcpy(dest, src, 5);
	memcpy(dest, src, 4);
	foo(src, 5);
	foo(dest, 5);
	//ft_memset(str, 'b', 10);
	//memset(str2, 'd', 10);
	//foo(str, 10);
	//foo(str2, 10);
	return (0);
}*/
