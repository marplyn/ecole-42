/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:20:25 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	is_rt_file(char *filename)
{
	int	length;

	length = ft_strlen(filename) - 1;
	if ((filename[length - 2] != '.') || (filename[length - 1] != 'r')
		|| (filename[length] != 't'))
		display_error_exit(FILE_EXTENTION_ERROR);
}

int	ft_arraylen(char **array)
{
	int	i;

	i = 1;
	while (array[i])
		i++;
	return (i);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*check_float_str(char *str)
{
	size_t	i;

	i = 0;
	if (!ft_isdigit(str[i]) && str[i] != '-')
		display_error_exit(ELEMENT_PARAMS_ERROR);
	i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (str);
	if (str[i] != '.')
		display_error_exit(ELEMENT_PARAMS_ERROR);
	i++;
	if (!ft_isdigit(str[i]))
		display_error_exit(ELEMENT_PARAMS_ERROR);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		display_error_exit(ELEMENT_PARAMS_ERROR);
	return (str);
}

char	*check_int_str(char *str)
{
	int	i;

	i = 0;
	if (!ft_isdigit(str[i]) && str[i] != '-')
		display_error_exit(ELEMENT_PARAMS_ERROR);
	i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		display_error_exit(ELEMENT_PARAMS_ERROR);
	return (str);
}
