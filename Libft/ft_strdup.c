/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:10:34 by dground           #+#    #+#             */
/*   Updated: 2021/10/07 15:54:57 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;
	char	*t;

	i = 0;
	while (s1[i])
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	t = str;
	while (*s1)
		*t++ = *s1++;
	*t = '\0';
	return (str);
}
