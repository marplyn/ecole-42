/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:26:09 by dground           #+#    #+#             */
/*   Updated: 2021/10/06 21:37:23 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	unsigned int	len;
	unsigned int	slen;

	len = 0;
	slen = ft_strlen(src);
	while (*dst && dstsize > 0)
	{
		dst++;
		len++;
		dstsize--;
	}
	while (*src && dstsize-- > 1)
		*dst++ = *src++;
	if (dstsize == 1 || *src == 0)
		*dst = '\0';
	return (slen + len);
}
