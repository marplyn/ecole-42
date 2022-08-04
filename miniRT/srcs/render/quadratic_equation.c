/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_equation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:52:01 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	*solve_quadratic_equation(float a, float b, float c)
{
	float	*result;
	float	discriminant;

	result = (float *)malloc(sizeof(float) * 2);
	if (!result)
		display_error_exit(MALLOC_ERROR);
	result[0] = NAN;
	result[1] = NAN;
	discriminant = b * b - 4 * a * c;
	if (discriminant < EPSILON)
		return (result);
	result[0] = (-b - sqrtf(discriminant)) / (2 * a);
	result[1] = (-b + sqrtf(discriminant)) / (2 * a);
	return (result);
}
