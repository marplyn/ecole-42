/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:11:38 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	*vector_new(float x, float y, float z)
{
	t_vector	*vector;

	vector = (t_vector *)malloc(sizeof(t_vector));
	if (!vector)
		display_error_exit(MALLOC_ERROR);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

t_vector	*vector_subtract(t_vector *a, t_vector *b)
{
	t_vector	*vector;

	vector = vector_new(a->x - b->x, a->y - b->y, a->z - b->z);
	return (vector);
}

t_vector	*vector_add(t_vector *a, t_vector *b)
{
	t_vector	*vector;

	vector = vector_new(a->x + b->x, a->y + b->y, a->z + b->z);
	return (vector);
}

t_vector	*vector_scalar_multiple(t_vector *a, float b)
{
	t_vector	*vector;

	vector = vector_new(a->x * b, a->y * b, a->z * b);
	return (vector);
}
