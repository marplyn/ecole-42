/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:21 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/11 17:24:19 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	tmp;

	src_len = ft_strlen((char *)src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (dst[i] && i < size)
		i++;
	tmp = i;
	j = 0;
	if (i < size)
	{
		while (src[j] && i + 1 < size)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	if (size < tmp + 1)
		return (size + src_len);
	return (src_len + tmp);
}
