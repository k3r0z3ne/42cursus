/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:20:50 by arotondo          #+#    #+#             */
/*   Updated: 2024/06/06 12:28:12 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	else if (s == 0)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s[start++];
	return (str);
}
/*
int	main(void)
{
	const char	input1[13] = "FAIL_SUCCESS!";
	const char	input2[35] = "i just want this part #############";
	const char	input3[5] = "01234";

	printf("test 1 : %s\n", ft_substr(input1, 5, 10));
	printf("test 2 : %s\n", ft_substr(input2, 5, 10));
	printf("test 3 : %s\n", ft_substr(input3, 10, 10));
	// l27 : printf("total size = %zu\n", total_size);
	// l49 : printf("taille de str = %zu\n", ft_strlen(str));
	return (0);
}*/