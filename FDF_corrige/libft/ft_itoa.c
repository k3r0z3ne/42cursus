/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:18:18 by arotondo          #+#    #+#             */
/*   Updated: 2024/06/03 14:39:44 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_int(long n)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	if (n >= 0 && n <= 9)
		i++;
	return ((size_t)(i));
}

static char	*ft_isnegative(long n)
{
	char	*ret;
	size_t	len;

	ret = NULL;
	len = count_int(-n);
	ret = ft_calloc((len + 2), sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = '-';
	n *= -1;
	while (len > 0)
	{
		ret[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	count;
	long	x;

	ret = NULL;
	x = n;
	if (n < 0)
	{
		ret = ft_isnegative(x);
		return (ret);
	}
	count = count_int(x);
	if (count == 0)
		return (NULL);
	ret = ft_calloc((count + 1), sizeof(char));
	if (!ret)
		return (NULL);
	while (count > 0)
	{
		ret[count - 1] = (n % 10) + 48;
		n /= 10;
		count--;
	}
	return (ret);
}

/*
int	main(void)
{
	int	test;

	test = 2147483647;
	printf("pos = %s\n", ft_itoa(test));
	printf("neg = %s\n", ft_itoa(-2147483648));
	return (0);
}*/