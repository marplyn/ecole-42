/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:05:49 by dground           #+#    #+#             */
/*   Updated: 2021/10/10 11:09:33 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strings_count(char const *s, char c)
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

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;

	if (!s)
		return (ft_strdup(""));
	if (!c)
		return (s);
	splitted = (char **)malloc(sizeof(char) * (ft_strings_count(s, c) + 1));
	if (!splitted)
		return (NULL);
	

	return (splitted);
}