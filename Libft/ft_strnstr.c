/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:43:28 by dground           #+#    #+#             */
/*   Updated: 2021/10/07 16:39:20 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = 0;
		while (needle[i] && haystack[i] == needle[i] && len > 0)
		{
			len--;
			i++;
		}
		if (needle[i] == '\0')
			return ((char *)haystack);
		len += i;
		len--;
		haystack++;
	}
	return (NULL);
}
