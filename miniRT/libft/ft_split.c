/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:51:13 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/11 18:22:35 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	free_if_crash(char **result, size_t n)
{
	while (n--)
		free(result[n]);
	free(result);
}

static size_t	next_word_len(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static void	k_inc(char const *s, size_t *k, char c)
{
	while (s[*k] == c)
		(*k)++;
}

struct	s_vars
{
	char	**result;
	size_t	i;
	size_t	j;
	size_t	k;
};

char	**ft_split(char const *s, char c)
{
	struct s_vars	v;

	if (!s)
		return ((char **) NULL);
	v.result = (char **)malloc(sizeof(char *) * (words_count(s, c) + 1));
	if (!v.result)
		return ((char **) NULL);
	v.i = 0;
	v.k = 0;
	while (v.i < words_count(s, c))
	{
		v.j = 0;
		v.result[v.i] = (char *)malloc(next_word_len(s + v.k, c) + 1);
		if (!(v.result[v.i]))
		{
			free_if_crash(v.result, v.i);
			return (NULL);
		}
		k_inc(s, &v.k, c);
		while (s[v.k] && s[v.k] != c)
			v.result[v.i][v.j++] = s[v.k++];
		v.result[v.i++][v.j] = '\0';
	}
	v.result[v.i] = (char *) NULL;
	return (v.result);
}
