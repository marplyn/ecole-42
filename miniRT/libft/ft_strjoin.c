/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:30:07 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/09 20:36:24 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	total_len;
	size_t	k;

	if (s1 == NULL || s2 == NULL)
		return ((char *) NULL);
	total_len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	res = (char *)malloc(sizeof(char) * total_len);
	if (!res)
		return ((char *) NULL);
	k = 0;
	while (*s1)
	{
		res[k++] = *s1;
		s1++;
	}
	while (*s2)
	{
		res[k++] = *s2;
		s2++;
	}
	res[k] = '\0';
	return (res);
}
