/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:17:56 by arotondo          #+#    #+#             */
/*   Updated: 2024/05/27 21:36:04 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*conv_d;
	unsigned const char	*conv_s;

	conv_d = (unsigned char *)dest;
	conv_s = (unsigned const char *)src;
	if (len == 0 || dest == src)
		return (dest);
	if (conv_d < conv_s)
	{
		while (len--)
		{
			*conv_d++ = *conv_s++;
		}
	}
	else
	{
		conv_d = conv_d + len;
		conv_s = conv_s + len;
		while (len--)
			*--conv_d = *--conv_s;
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
	char	src[5] = "12345";
	char	dest[5] = "00000";

	ft_memmove(dest, src, 5);
	memmove(dest, src, 5);
	foo(src, 5);
	foo(dest, 5);
	return (0);
}*/
