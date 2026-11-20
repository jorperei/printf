/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 13:15:41 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/18 19:32:59 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char sep)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i] != '\0')
			j++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (j);
}

static void	free_a(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}

static char	**fill_words(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	wlen;

	i = 0;
	k = 0;
	while (k < count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		wlen = 0;
		while (s[i + wlen] && s[i + wlen] != c)
			wlen++;
		arr[k] = ft_substr(s, i, wlen);
		if (!arr[k])
		{
			free_a(arr, k);
			return (NULL);
		}
		i = i + wlen;
		k++;
	}
	arr[count_words(s, c)] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (fill_words(arr, s, c));
}

/*
int	main(void)
{
	char	**teste;
	size_t	i;

	teste = ft_split("  gosto de sushi  ", ' ');
	if (!teste)
		return (1);
	i = 0;
	while (teste[i])
	{
		printf("[%zu] \"%s\"\n", i, teste[i]);
		free(teste[i]);
		i++;
	}
	free(teste);
	return (0);
}*/