/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:53:57 by arotondo          #+#    #+#             */
/*   Updated: 2024/05/24 17:25:36 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_conv;
	size_t			i;

	s_conv = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s_conv[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	str[5] = "22222";

	ft_bzero(&str, 4);
	return (0);
}*/
