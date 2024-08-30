/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:23:57 by arotondo          #+#    #+#             */
/*   Updated: 2024/05/30 11:34:05 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new_s;

	len = ft_strlen(s1) + ft_strlen(s2);
	new_s = ft_calloc((len + 1), sizeof(char));
	if (!(new_s))
		return (NULL);
	ft_memcpy(new_s, s1, ft_strlen(s1));
	ft_strlcat(new_s, s2, len + 1);
	return (new_s);
}*/

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
/*
int	main(void)
{
	char	*s1 = "Maman,_TH_";
	char	*s2 = "a_le_dernier_BM";

	printf("ft_strjoin = %s\n", ft_strjoin(s1, s2));
	return (0);
}
*/
