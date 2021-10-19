/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:54:59 by dground           #+#    #+#             */
/*   Updated: 2021/10/19 13:17:57 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
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

char	*ft_strchr(char *s, int c)
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

char	*ft_strcpy(char *str, char *leftover)
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

char	*ft_strcat(char *str, char *buff)
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

char	*ft_strjoin(char *leftover, char *buff)
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
	length = ft_strlen(leftover) + ft_strlen(buff) + 1;
	str = (char *)malloc(sizeof(char) * length);
	if (str == NULL)
		return (NULL);
	if (leftover)
		ft_strcpy(str, leftover);
	ft_strcat(str, buff);
	free(leftover);
	return (str);
}

/*char	*ft_strjoin(char *leftover, char *buff)
{
	char	*str;
	size_t	i;
	size_t	j;	

	i = -1;
	j = 0;
	if (!leftover)
	{
		leftover = (char *)malloc(sizeof(char) * 1);
		leftover[0] = '\0';
	}
	if (!leftover || !buff)
		return (NULL);
	str = (char *)malloc(ft_strlen(leftover) + ft_strlen(buff) + 1);
	if (!str)
		return (NULL);
	if (leftover)
		while (leftover[++i] != '\0')
			str[i] = leftover[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(leftover) + ft_strlen(buff)] = '\0';
	free(leftover);
	return (str);
}*/
