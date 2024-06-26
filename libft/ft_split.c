/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:59:20 by arotondo          #+#    #+#             */
/*   Updated: 2024/06/03 18:13:58 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char sep)
{
	size_t	x;
	size_t	nb;

	x = 0;
	nb = 0;
	while (str[x] != '\0')
	{
		if (str[x] != sep && (str[x + 1] == sep || str[x + 1] == '\0'))
			nb++;
		x++;
	}
	return (nb);
}

static char	*ft_check(char const *s, char sep)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (count_words(s, sep) == 0)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == sep)
			n++;
		i++;
	}
	if (n == 0)
		return (NULL);
	else
		return ((char *)(s));
}

static void	ft_free(char **tab, size_t word)
{
	while (word > 0)
	{
		if (tab[word] != NULL)
			free(tab[word]);
		word--;
	}
	free (tab);
	return ;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word;
	char	**tab;

	ft_check(s, c);
	tab = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	word = 0;
	while (word < count_words(s, c))
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		tab[word] = ft_calloc((i - j + 1), sizeof(char));
		if (!tab[word])
			ft_free(tab, word);
		ft_strlcpy(tab[word], (s + j), (i - j + 1));
		word++;
	}
	return (tab);
}

/*
int main(void)
{
	size_t	i;
	char *str = "  Tous les matins,  tous  les soirs  ?  Jai...";
	char separateur = ' ';
	char **res;

	i = 0;
	res = ft_split(str, separateur);
	while (res[i])
	{
		printf("%s\n", res[i]);
		free(res[i++]);
	}
	free(res);
	return (0);
}*/