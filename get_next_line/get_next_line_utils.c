/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:11:29 by arotondo          #+#    #+#             */
/*   Updated: 2024/06/26 16:26:42 by arotondo         ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	int		srclen;
	char	*dup;
	int		i;

	srclen = ft_strlen(src);
	dup = malloc((srclen + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// modification de strjoin : remplacement de calloc par malloc, en cas d'erreur verifier le bon placement du '\0'
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	srclen;
	size_t	i;
	char	*ret;

	len = ft_strlen(s1) + ft_strlen(s2);
	srclen = ft_strlen(s1);
	i = 0;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (s1[i])
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
	ret[srclen + i] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	else if (s == 0)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
