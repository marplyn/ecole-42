/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:51:52 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_sphere	*sphere_new(t_vector *center, float radius, unsigned int hex_rgb)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		display_error_exit(MALLOC_ERROR);
	sphere->center = center;
	sphere->radius = radius;
	sphere->hex_rgb = hex_rgb;
	return (sphere);
}

t_bool	is_sphere_intersect(t_sphere *sphere, t_ray *ray)
{
	t_vector	*l;
	float		tca;
	float		d2;
	float		t1;
	float		distance;

	l = vector_subtract(sphere->center, ray->origin);
	tca = vector_dot_product(l, ray->direction);
	d2 = vector_dot_product(l, l) - powf(tca, 2);
	free(l);
	if (d2 > powf(sphere->radius, 2))
		return (false);
	distance = tca - sqrtf(powf(sphere->radius, 2) - d2);
	t1 = tca + sqrtf(powf(sphere->radius, 2) - d2);
	if (distance > t1)
		ft_swap_float(&distance, &t1);
	if (distance < 0.0)
		distance = t1;
	if (distance < 0.0 || distance < EPSILON || distance > ray->distance)
		return (false);
	ray->distance = distance;
	return (true);
}

t_bool	sphere_find_intersection(t_sphere *sphere, t_ray *ray)
{
	t_vector	*vector_multiplied;

	if (is_sphere_intersect(sphere, ray))
	{
		vector_multiplied = vector_scalar_multiple(ray->direction,
				ray->distance);
		ray->point = vector_add_stack(*ray->origin, *vector_multiplied);
		free(vector_multiplied);
		ray->normal = vector_subtract_stack(ray->point, *sphere->center);
		vector_normalize(&ray->normal);
		ray->hex_rgb = sphere->hex_rgb;
		return (true);
	}
	return (false);
}
