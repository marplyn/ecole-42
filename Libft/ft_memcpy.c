/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:44:22 by dground           #+#    #+#             */
/*   Updated: 2021/10/07 21:20:45 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*c_src;
	char	*c_dst;

	c_src = (char *)src;
	c_dst = (char *)dst;
	if (dst != 0 || src != 0)
	{
		while (n)
		{
			*(c_dst++) = *(c_src++);
			--n;
		}
	}
	return (dst);
}
