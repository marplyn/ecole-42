/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 07:24:53 by sserwyn           #+#    #+#             */
/*   Updated: 2022/08/01 07:44:00 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	init_for_cc1(t_plane *pl, t_vector *v, t_cylinder cylinder)
{
	pl->normal = cylinder.normal;
	pl->hex_rgb = cylinder.args.hex_rgb;
	*v = vector_scalar_multiple_stack(*cylinder.normal, cylinder.args.height);
	pl->point = vector_add(cylinder.point, v);
}

t_bool	intersect_cylinder_cap_1(t_cylinder *cylinder, t_ray *ray,
	float *distance)
{
	t_plane		pl;
	t_vector	vector_modified;

	init_for_cc1(&pl, &vector_modified, *cylinder);
	if (is_plane_intersect(&pl, *ray, distance) && *distance > EPSILON
		&& *distance < ray->distance)
	{
		vector_modified = vector_subtract_stack(vector_add_stack(\
			*ray->origin, vector_scalar_multiple_stack(*ray->direction, \
				*distance)), *pl.point);
		if (vector_length(&vector_modified) < (cylinder->args.radius))
		{
			free(pl.point);
			ray->point = vector_add_stack(*ray->origin, \
				vector_scalar_multiple_stack(*ray->direction, ray->distance));
			ray->normal = *cylinder->normal;
			if (vector_dot_product(cylinder->normal, ray->direction) > 0)
				ray->normal = vector_scalar_multiple_stack(ray->normal, -1);
			vector_normalize(&ray->normal);
			return (true);
		}
	}
	free(pl.point);
	return (false);
}

t_bool	intersect_cylinder_cap_2(t_cylinder *cylinder, t_ray *ray,
	float *distance)
{
	t_vector	point;
	t_vector	vector_modified;

	if (is_plane_intersect((t_plane *) cylinder, *ray, distance) && \
		*distance > EPSILON && *distance < ray->distance)
	{
		point = vector_add_stack(*ray->origin, \
			vector_scalar_multiple_stack(*ray->direction, *distance));
		vector_modified = vector_subtract_stack(point, *cylinder->point);
		if (vector_length(&vector_modified) < (cylinder->args.radius))
		{
			ray->point = vector_add_stack(*ray->origin, \
			vector_scalar_multiple_stack(*ray->direction, ray->distance));
			ray->normal = *cylinder->normal;
			if (vector_dot_product(cylinder->normal, ray->direction) > 0)
				ray->normal = vector_scalar_multiple_stack(ray->normal, -1);
			return (true);
		}
	}
	return (false);
}

static float	*init_for_icp_abc(t_cylinder cylinder, t_ray ray)
{
	float		a;
	float		b;
	float		c;
	t_vector	*oc;

	oc = vector_subtract(ray.origin, cylinder.point);
	a = 1 - powf(vector_dot_product(ray.direction, cylinder.normal), 2);
	b = 2 * (vector_dot_product(ray.direction, oc)
			- vector_dot_product(ray.direction, cylinder.normal)
			* vector_dot_product(oc, cylinder.normal));
	c = vector_dot_product(oc, oc)
		- powf(vector_dot_product(oc, cylinder.normal), 2)
		- powf(cylinder.args.radius, 2);
	free(oc);
	return (solve_quadratic_equation(a, b, c));
}

t_bool	intersect_cylinder_pipe(t_cylinder *cylinder, t_ray ray, \
	float *distance)
{
	float		t;
	float		*cyl_roots;

	t = 0;
	cyl_roots = init_for_icp_abc(*cylinder, ray);
	if (!cyl_roots[0] && !cyl_roots[1])
	{
		free(cyl_roots);
		return (false);
	}
	if (cyl_roots[0] < cyl_roots[1])
		t = cyl_roots[0];
	if (t < EPSILON || t > ray.distance)
	{
		free(cyl_roots);
		return (false);
	}
	*distance = t;
	free(cyl_roots);
	return (true);
}
