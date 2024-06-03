/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:01:35 by arotondo          #+#    #+#             */
/*   Updated: 2024/06/03 14:58:56 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	len;
	size_t	i;

	ret = NULL;
	len = ft_strlen(s);
	ret = ft_calloc((len + 1), sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	return (ret);
}
/*
int	main(void)
{
	char const	*str;

	str = "Will you rage ??";
	printf("%s\n", ft_strmapi(str, ))
}*/