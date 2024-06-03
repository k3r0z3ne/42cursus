/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:57:41 by arotondo          #+#    #+#             */
/*   Updated: 2024/05/28 14:43:42 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else if (c > 64 && c < 91)
		return (1);
	else if (c > 96 && c < 123)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	printf("%d\n", ft_isalnum(*argv[1]));
	return (0);
}*/
