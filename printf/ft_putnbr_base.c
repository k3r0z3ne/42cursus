/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:28:12 by arotondo          #+#    #+#             */
/*   Updated: 2024/06/19 17:38:01 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_base(char *base)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(base);
	i = 0;
	if (len < 2)
		return (1);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			else if (base[j] == '-' || base[j] == '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_return_len(unsigned long long nb, long base_len)
{
	int	count;

	count = 1;
	if (nb < 0)
		nb = base_len - nb;
	while (nb / base_len)
	{
		nb /= base_len;
		count++;
	}
	return (count);
}

int	ft_checksign(long nb, char *base)
{
	if (nb < 0)
	{
		nb *= -1;
		nb = 4294967296 - nb;
	}
	return (ft_putnbr_base(nb, base));
}

int	ft_putnbr_base(unsigned long nb, char *base)
{
	unsigned long	base_len;
	unsigned long	nb_conv;

	base_len = ft_strlen((const char *)(base));
	nb_conv = nb;
	if (check_base(base) == 1)
		return (0);
	if (nb_conv < 0)
		base[nb_conv] = base[base_len - nb_conv];
	else if (nb_conv >= base_len)
	{
		ft_putnbr_base(nb_conv / base_len, base);
		ft_putchar(base[nb_conv % base_len]);
	}
	else
		ft_putchar(base[nb_conv]);
	return (ft_return_len(nb_conv, base_len));
}
/*
int	main(void)
{
	write(1, "42:", 3);
	ft_putnbr_base(42, "0123456789");
	write(1, "\n2a:", 4);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n-2a:", 5);
	ft_putnbr_base(-42, "0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "0");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "+-0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "\t0123456789abcdef");
}*/
/*
#include <stdio.h>
int	main(void)
{
	ft_putnbr_base(9995, "0123456789abcdef");
	printf("\n");
	ft_putnbr_base(150, "poneyvif");
	printf("\n");
	ft_putnbr_base(9995, "+01");
	printf("\n");
	ft_putnbr_base(9995, "1");
	printf("\n");
	ft_putnbr_base(-9995, "-0123456789");
	printf("\n");
	ft_putnbr_base(-2147483648, "01234563789");
}*/
/*
#include <stdlib.h>
int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	ft_putnbr_base(atoi(argv[1]), argv[2]);
	return (0);
}*/