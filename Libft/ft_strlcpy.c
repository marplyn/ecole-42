/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:50:25 by dground           #+#    #+#             */
/*   Updated: 2021/10/11 20:24:46 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (!dstsize)
		return (len);
	i = 0;
	while (src[i] && (i + 1 < dstsize))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
