/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:05:49 by dground           #+#    #+#             */
/*   Updated: 2021/10/12 12:49:48 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
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

static size_t	ft_word_length(char const *s, char c)
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

static void	ft_free_after_error(char **splitted, size_t n)
{
	while (n--)
		free(splitted[n]);
	free(splitted);
}

static void	ft_go_to_next_word(char const *s, size_t *k, char c)
{
	while (s[*k] == c)
		(*k)++;
}

typedef struct s_var
{
	char	**splitted;
	size_t	i;
	size_t	j;
	size_t	k;
}	t_var;

char	**ft_split(char const *s, char c)
{
	t_var	t;

	if (!s)
		return (NULL);
	t.splitted = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!t.splitted)
		return (NULL);
	t.i = 0;
	t.k = 0;
	while (t.i < ft_word_count(s, c))
	{
		t.j = 0;
		t.splitted[t.i] = (char *)malloc(ft_word_length(s + t.k, c) + 1);
		if (!(t.splitted[t.i]))
		{
			ft_free_after_error(t.splitted, t.i);
			return (NULL);
		}
		ft_go_to_next_word(s, &t.k, c);
		while (s[t.k] && s[t.k] != c)
			t.splitted[t.i][t.j++] = s[t.k++];
		t.splitted[t.i++][t.j] = '\0';
	}
	t.splitted[t.i] = NULL;
	return (t.splitted);
}
