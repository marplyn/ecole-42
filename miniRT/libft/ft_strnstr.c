/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:45:31 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/06 23:04:50 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!small[i])
		return ((char *) big);
	while (i < size && big[i])
	{
		j = 0;
		while (big[i + j] && small[j] && big[i + j] == small[j] && i + j < size)
			j++;
		if (!small[j])
			return ((char *)(big + i));
		i++;
	}
	return ((char *) NULL);
}
