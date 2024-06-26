/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:52:24 by arotondo          #+#    #+#             */
/*   Updated: 2024/05/24 19:29:18 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*conv_s1;
	const unsigned char	*conv_s2;

	conv_s1 = (unsigned char *)s1;
	conv_s2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*conv_s1 != *conv_s2)
		{	
			return (*conv_s1 - *conv_s2);
		}
		conv_s1++;
		conv_s2++;
		n--;
	}
	return (0);
}
/*
int	main(void)
{
	unsigned char	str1[8] = "BonSour";
	unsigned char	str2[8] = "bonsoir";

	printf("%d\n", ft_memcmp(str1, str2, 5));
	return (1);
}*/
