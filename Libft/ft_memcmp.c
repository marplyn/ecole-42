/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:23:14 by dground           #+#    #+#             */
/*   Updated: 2021/10/07 13:47:47 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	if (n != 0 && (s1 && s2))
	{
		p1 = (unsigned char *)s1;
		p2 = (unsigned char *)s2;
		i = 0;
		while (n - i)
		{
			if (p1[i] != p2[i])
				return (p1[i] - p2[i]);
			i++;
		}
	}
	return (0);
}
