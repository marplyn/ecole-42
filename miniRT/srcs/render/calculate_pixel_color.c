/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_pixel_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:41:17 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 07:06:35 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static float	shadow_init(t_ray *shadow, t_light *light, t_vector *p)
{
	float	max_distance;

	shadow->point = (t_vector){0, 0, 0};
	shadow->normal = (t_vector){0, 0, 0};
	shadow->origin = p;
	shadow->direction = vector_subtract(light->center, p);
	max_distance = vector_length(shadow->direction);
	vector_normalize(shadow->direction);
	shadow->distance = max_distance;
	return (max_distance);
}

void	apply_hex_rgb(t_ray *ray, t_filtered_elements elements, \
	unsigned int color, float intensity)
{
	ray->hex_rgb = calculate_ambient_color(elements.ambient_lights,
			ray->hex_rgb);
	ray->hex_rgb = hex_rgb_add(color, ray->hex_rgb);
	ray->hex_rgb = hex_rgb_apply_brightness(ray->hex_rgb, intensity);
}

unsigned int	calculate_pixel_color(t_filtered_elements elements, t_ray *ray)
{
	t_ray			shadow;
	float			max_distance;
	unsigned int	color;
	float			intensity;
	t_light			*light;

	color = BLACK_COLOR;
	intensity = 0;
	while (elements.lights)
	{
		light = elements.lights->content;
		max_distance = shadow_init(&shadow, light, &ray->point);
		if (!(is_shadow_intersect(elements, &shadow)
				&& shadow.distance > EPSILON && shadow.distance < max_distance))
		{
			intensity += calculate_light_intensity(&ray->normal,
					shadow.direction, light);
			color = calculate_light_color(light, color);
		}
		free(shadow.direction);
		elements.lights = elements.lights->next;
	}
	intensity += calculate_ambient_intensity(elements.ambient_lights);
	apply_hex_rgb(ray, elements, color, intensity);
	return (ray->hex_rgb);
}
