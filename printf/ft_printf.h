/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:36:37 by arotondo          #+#    #+#             */
/*   Updated: 2024/06/15 17:37:51 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(const char *str);
int		ft_putnbr(int nb);
int		ft_putnbr_base(unsigned long nb, char *base);
int		ft_put_unsigned(unsigned int nb);
int		ft_putptr(void *address);
int		ft_checksign(long nb, char *base);
size_t	ft_strlen(const char *str);
size_t	ft_len(long nb);

#endif