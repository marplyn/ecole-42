/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:34:50 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/06 23:16:14 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;

	len = ft_strlen((char *)s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return ((char *) NULL);
	ft_strlcpy(res, s, len + 1);
	return (res);
}
