/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:38:37 by arotondo          #+#    #+#             */
/*   Updated: 2024/05/27 21:09:14 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*conv_s;
	size_t				i;

	conv_s = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (conv_s[i] == (unsigned char)c)
		{
			return ((void *)conv_s + i);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[13] = "abraca\\0dabra";

	ft_memchr(str, '\0', 10);
	//printf("%c\n", str[7]);
	//printf("adresse de str[7] : %p\n", &str[7]);
	// A placer ligne 26/27 pour test :
	//printf("caractere trouve : %c\n", conv_s[i]);
	//printf("adresse de conv_s[i] : %p\n", &conv_s[i]);
	return (0);
}*/
