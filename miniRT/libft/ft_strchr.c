/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:07:49 by sserwyn           #+#    #+#             */
/*   Updated: 2021/10/07 19:54:18 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	letter;
	char	*str;

	i = 0;
	letter = (char) c;
	str = (char *) s;
	while (str[i])
	{
		if (str[i] == letter)
			return (str + i);
		i++;
	}
	if (str[i] == '\0' && letter == '\0')
		return (str + i);
	return ((char *) NULL);
}
