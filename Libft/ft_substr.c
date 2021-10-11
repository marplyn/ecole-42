/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:55:13 by dground           #+#    #+#             */
/*   Updated: 2021/10/11 18:07:51 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_var
{
	size_t	j;
	size_t	i;
}	t_var;

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	t_var	t;

	if (s == NULL)
		return (NULL);
	t.i = start;
	if (t.i >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	t.j = 0;
	while (s[t.i++] != '\0' && t.j < len)
		t.j++;
	str = (char *)malloc(sizeof(char) * t.j + 1);
	if (!str)
		return (NULL);
	t.j = 0;
	while (s[start] != '\0' && t.j < len)
		str[t.j++] = s[start++];
	str[t.j] = '\0';
	return (str);
}
