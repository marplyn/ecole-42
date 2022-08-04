/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:37:34 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/09 20:50:19 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start_index;
	size_t	end_index;

	if (s1 == NULL || set == NULL)
		return ((char *) NULL);
	start_index = 0;
	while (s1[start_index] && ft_strchr(set, s1[start_index]))
		start_index++;
	end_index = ft_strlen((char *)s1) - 1;
	while (end_index > start_index && ft_strchr(set, s1[end_index]))
		end_index--;
	res = ft_substr(s1, start_index, end_index + 1 - start_index);
	return (res);
}
