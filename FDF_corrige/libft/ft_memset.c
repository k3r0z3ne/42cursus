/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:15:43 by arotondo          #+#    #+#             */
/*   Updated: 2024/05/24 17:25:57 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t size)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < size)
	{
		p[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
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
	char	str[10];
	char	str2[10];
	ft_memset(str, 'a', 10);
	memset(str2, 'c', 10);
	foo(str, 10);
	foo(str2, 10);
	ft_memset(str, 'b', 10);
	memset(str2, 'd', 10);
	foo(str, 10);
	foo(str2, 10);
	//printf("memset : %p\n", memset(str, 'a', size));
	return (0);
}*/
