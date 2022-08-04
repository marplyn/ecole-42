/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:22:01 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	check_commas(char *array)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
	{
		if ((array[i] == ',' && array[i + 1] == ',') || (array[0] == ',')
			|| (array[i + 1] == '\0' && array[i] == ','))
			display_error_exit(ELEMENT_PARAMS_ERROR);
		i++;
	}
}

unsigned int	parse_colors(char *array)
{
	char			**colors;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	check_commas(array);
	colors = ft_split(array, ',');
	if (colors == NULL)
		display_error_exit(PARSE_ERROR);
	if (ft_arraylen(colors) != 3)
		display_error_exit(ELEMENT_PARAMS_ERROR);
	red = ft_atoi(check_int_str(colors[0]));
	green = ft_atoi(check_int_str(colors[1]));
	blue = ft_atoi(check_int_str(colors[2]));
	if (!(red >= 0 && red <= 255) || !(green >= 0 && green <= 255)
		|| !(blue >= 0 && blue <= 255))
		display_error_exit(ELEMENT_PARAMS_ERROR);
	ft_free_array(colors);
	return (rgb_to_hex(red, green, blue));
}

t_vector	*parse_coordinates(char *array)
{
	char	**coordinates;
	float	x;
	float	y;
	float	z;

	check_commas(array);
	coordinates = ft_split(array, ',');
	if (coordinates == NULL)
		display_error_exit(PARSE_ERROR);
	if (ft_arraylen(coordinates) != 3)
		display_error_exit(ELEMENT_PARAMS_ERROR);
	x = ft_atof(check_float_str(coordinates[0]));
	y = ft_atof(check_float_str(coordinates[1]));
	z = ft_atof(check_float_str(coordinates[2]));
	ft_free_array(coordinates);
	return (vector_new(x, y, z));
}

t_vector	*parse_vector(char *array)
{
	char	**vector;
	float	x;
	float	y;
	float	z;

	check_commas(array);
	vector = ft_split(array, ',');
	if (vector == NULL)
		display_error_exit(PARSE_ERROR);
	if (ft_arraylen(vector) != 3)
		display_error_exit(ELEMENT_PARAMS_ERROR);
	x = ft_atof(check_float_str(vector[0]));
	y = ft_atof(check_float_str(vector[1]));
	z = ft_atof(check_float_str(vector[2]));
	if (!(x >= -1.0 && x <= 1.0) || !(y >= -1.0 && y <= 1.0)
		|| !(y >= -1.0 && y <= 1.0))
		display_error_exit(ELEMENT_PARAMS_ERROR);
	ft_free_array(vector);
	return (vector_new(x, y, z));
}
