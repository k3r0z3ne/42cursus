/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:39:19 by arotondo          #+#    #+#             */
/*   Updated: 2024/06/26 17:25:46 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_conv(char c, int *ret, va_list args)
{
	if (c == 'c')
		*ret += ft_putchar(va_arg(args, int));
	else if (c == 's')
		*ret += ft_putstr(va_arg(args, char *));
	else if (c == 'i')
		*ret += ft_putnbr(va_arg(args, int));
	else if (c == 'd')
		*ret += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		*ret += ft_put_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		*ret += ft_checksign(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		*ret += ft_checksign(va_arg(args, int), "0123456789ABCDEF");
	else if (c == '%')
		*ret += ft_putchar('%');
	else if (c == 'p')
		*ret += ft_putptr(va_arg(args, void *));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	if (!format)
		return (-1);
	ret = 0;
	while (*format)
	{
		if (*format == '%')
			ft_conv(*++format, &ret, args);
		else
		{
			ft_putchar(*format);
			if (!*format)
				return (-1);
			ret++;
		}
		format++;
	}
	va_end(args);
	return (ret);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	ft_printf("==================================\n");
	ft_printf("test de ft_printf == %d\n", atoi(argv[1]));
	printf("test de printf == %d\n", atoi(argv[1]));
	ft_printf("==================================\n");
	return (0);
}*/

// int	main(void)
// {
// 	int ret;
// 	//ft_printf("test ft_printf == %x\n", -16);
// 	ret = ft_printf("hello");
// 	//printf("test printf == %x\n", -16);
// 	return (printf("%d", ret));
// }