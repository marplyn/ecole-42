/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:05:49 by dground           #+#    #+#             */
/*   Updated: 2021/10/11 21:32:22 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s && c)
	{
		while (s[i])
		{
			while (s[i] == c)
				i++;
			if (s[i])
				count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while ((src[i] != '\0') && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while ((dest[i] != '\0') && (i < n))
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

/*static void	ft_free_error(char **result, size_t n)
{
	while (n--)
		free(splitted[n]);
	free(splitted);
}*/

typedef struct s_var
{
	char	**splitted;
	int		i;
	int		j;
	int		k;
}	t_var;

char	**ft_split(char const *s, char c)
{
	t_var	t;

	t.i = 0;
	t.k = 0;
	if (!s)
		return (NULL);
	t.splitted = (char **)malloc(sizeof(char *) * (ft_word_count(s, c)) + 1);
	if (!t.splitted)
		return (NULL);
	while (s[t.i])
	{
		while (s[t.i] == c)
			t.i++;
		t.j = t.i;
		while (s[t.i] && s[t.i] != c)
			t.i++;
		if (t.i > t.j)
		{
			t.splitted[t.k] = ft_strndup(s + t.j, t.i - t.j);
			t.k++;
		}
	}
	t.splitted[t.k] = NULL;
	return (t.splitted);
}