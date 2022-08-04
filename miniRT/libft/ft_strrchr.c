/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:19:26 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/07 19:56:19 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*res;

	ptr = (char *)s;
	res = (char *) NULL;
	while (*ptr != '\0')
	{
		if (*ptr == (char) c)
			res = ptr;
		ptr++;
	}
	if (*ptr == '\0' && c == '\0')
		return (ptr);
	return (res);
}
