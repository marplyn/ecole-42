/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:11:04 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 00:11:33 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	vector_length(t_vector *vector)
{
	float	result;

	result = sqrtf(vector->x * vector->x + vector->y
			* vector->y + vector->z * vector->z);
	return (result);
}

void	vector_normalize(t_vector *vector)
{
	float	length;

	length = vector_length(vector);
	vector->x /= length;
	vector->y /= length;
	vector->z /= length;
}

float	vector_dot_product(t_vector *a, t_vector *b)
{
	float	result;

	result = (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
	return (result);
}
