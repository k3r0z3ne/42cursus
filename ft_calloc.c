/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:04:40 by arotondo          #+#    #+#             */
/*   Updated: 2024/05/27 21:01:12 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	total_len;

	total_len = nmemb * size;
	tab = malloc(total_len);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, total_len);
	return (tab);
}
/*
int	main(void)
{
	ft_calloc(40, 4);
	//calloc(1, 4);
	//a placer ligne 34 pour test :
	//printf("%d", tab[i]);
	//tab = (void *)malloc(nmemb * sizeof(char));
	return (0);
}*/
