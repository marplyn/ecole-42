/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:27:03 by dground           #+#    #+#             */
/*   Updated: 2021/10/07 21:58:48 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)dst;
	if (dst != 0 || src != 0)
	{
		if (src < dst)
		{
			while (len--)
				*((unsigned char *)(dst + len)) = *((unsigned char *)(src
							+ len));
		}
		else
		{
			while (len--)
				*(unsigned char *)dst++ = *(unsigned char *)src++;
		}
	}
	return (tmp);
}
