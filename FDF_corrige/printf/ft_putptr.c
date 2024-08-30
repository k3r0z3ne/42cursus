/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:06:35 by arotondo          #+#    #+#             */
/*   Updated: 2024/06/19 16:05:50 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *address)
{
	unsigned long	buffer;

	buffer = (unsigned long)address;
	if (!buffer)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (ft_putnbr_base(buffer, "0123456789abcdef") + 2);
}
