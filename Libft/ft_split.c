/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:05:49 by dground           #+#    #+#             */
/*   Updated: 2021/10/11 16:49:29 by dground          ###   ########.fr       */
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

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	splitted = (char **)malloc(sizeof(char *) * (ft_word_count(s, c)) + 1);
	if (splitted == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			splitted[k] = ft_strndup(s + j, i - j);
			k++;
		}
	}
	splitted[k] = NULL;
	return (splitted);
}
