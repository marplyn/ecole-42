/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:54:59 by dground           #+#    #+#             */
/*   Updated: 2022/05/03 21:47:58 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_sl_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	if (!s)
		return (0);
	if ((char)c == '\0')
		return ((char *)s);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strcpy_gnl(char *str, char *leftover)
{
	int	i;

	i = 0;
	while (leftover[i] != '\0')
	{
		str[i] = leftover[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strcat_gnl(char *str, char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	while (buff[j] != '\0')
	{
		str[i + j] = buff[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char *leftover, char *buff)
{
	char	*str;
	size_t	length;

	if (!leftover)
	{
		leftover = (char *)malloc(sizeof(char) * 1);
		leftover[0] = '\0';
	}
	if (!leftover || !buff)
		return (NULL);
	length = ft_sl_gnl(leftover) + ft_sl_gnl(buff) + 1;
	str = (char *)malloc(sizeof(char) * length);
	if (str == NULL)
		return (NULL);
	if (leftover)
		ft_strcpy_gnl(str, leftover);
	ft_strcat_gnl(str, buff);
	free(leftover);
	return (str);
}
