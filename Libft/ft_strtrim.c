/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:34:21 by dground           #+#    #+#             */
/*   Updated: 2021/10/09 23:58:58 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_char(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		untrimmed_len;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup((char *) s1));
	untrimmed_len = ft_strlen(s1);
	i = 0;
	while (ft_check_char(s1[i], set))
		i++;
	if (i == untrimmed_len)
		return (ft_strdup(""));
	while (ft_check_char(s1[untrimmed_len - 1], set))
		untrimmed_len--;
	trimmed = (char *)malloc(sizeof(char) * (untrimmed_len - i + 1));
	if (!trimmed)
		return (NULL);
	j = 0;
	while (i < untrimmed_len)
		trimmed[j++] = s1[i++];
	trimmed[j] = '\0';
	return (trimmed);
}
