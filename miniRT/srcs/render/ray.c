/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:41:40 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_ray	ray_new(t_vector *origin, t_vector *direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	ray.normal = (t_vector){0, 0, 0};
	ray.point = (t_vector){0, 0, 0};
	ray.distance = INFINITY;
	ray.hex_rgb = NAN;
	return (ray);
}
