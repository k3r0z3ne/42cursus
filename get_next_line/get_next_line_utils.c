/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:11:29 by arotondo          #+#    #+#             */
/*   Updated: 2024/07/03 16:36:06 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		srclen;
	char	*dup;
	int		i;

	srclen = ft_strlen(src);
	dup = (char *)ft_calloc((srclen + 1), sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	srclen;
	size_t	i;	
	char	*ret;

	srclen = ft_strlen(s1);
	i = 0;
	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	ret = (char *)ft_calloc((srclen + ft_strlen(s2) + 1), sizeof(char));
	if (!ret)
		return (free (s1), NULL);
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ret[srclen + i] = s2[i];
		i++;
	}
	return (free (s1), ret);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	char	*conv_tab;
	size_t	total_len;
	size_t	i;

	total_len = nmemb * size;
	i = 0;
	tab = malloc(total_len);
	if (!tab)
		return (NULL);
	conv_tab = (char *)tab;
	while (i < total_len)
	{
		conv_tab[i] = 0;
		i++;
	}
	return ((void *)conv_tab);
}

char	*ft_strchr(char *str, int to_find)
{
	while (*str != '\0')
	{
		if (*str == (char)to_find)
			return ((char *)str);
		str++;
	}
	if (*str == (char)to_find)
		return ((char *)str);
	return (NULL);
}
