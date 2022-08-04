/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_direction_calc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:44:38 by sserwyn           #+#    #+#             */
/*   Updated: 2022/08/01 23:09:14 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_vector	calc_matrix_vx(t_vector camera)
{
	t_vector	vx;

	vx.z = 0;
	if (!camera.x && !camera.y)
	{
		vx.y = 0;
		if (camera.z > 0)
			vx.x = -1.0;
		else if (camera.z < 0)
			vx.x = 1.0;
		else if (!camera.z)
			display_error_exit(ELEMENT_PARAMS_ERROR);
	}
	else
	{
		vx.x = camera.y;
		vx.y = -1.0 * camera.x;
	}
	return (vx);
}

static t_vector	vector_cross_product_stack(t_vector v1, t_vector v2)
{
	t_vector	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}

static t_vector	matrix_vector_product_stack(t_matrix m, t_vector v)
{
	t_vector	mv;

	mv.x = v.x * m.vx.x + v.y * m.vy.x + v.z * m.vz.x;
	mv.y = v.x * m.vx.y + v.y * m.vy.y + v.z * m.vz.y;
	mv.z = v.x * m.vx.z + v.y * m.vy.z + v.z * m.vz.z;
	return (mv);
}

static t_vector	camera_ray(unsigned int fov, double x, double y)
{
	t_vector	dir;
	double		scale;
	double		image_aspect_ratio;

	image_aspect_ratio = WINDOW_WIDTH / WINDOW_HEIGHT;
	scale = tanf(((float)fov / 2.0) * M_PI / 180.0);
	dir.x = (2 * (x + 0.5) / WINDOW_WIDTH - 1) * image_aspect_ratio * scale;
	dir.y = (1 - 2 * (y + 0.5) / WINDOW_HEIGHT) * scale;
	dir.z = -1.0;
	vector_normalize(&dir);
	return (dir);
}

t_vector	camera_direction_calc(t_camera camera, int x, int y)
{
	t_matrix	matrix;
	t_vector	result;
	t_vector	ray_direction;

	ray_direction = camera_ray(camera.fov_angle, x, y);
	matrix.vx = calc_matrix_vx(*camera.direction);
	matrix.vy = vector_cross_product_stack(matrix.vx, *camera.direction);
	matrix.vz = vector_scalar_multiple_stack(*camera.direction, -1);
	vector_normalize(&matrix.vx);
	vector_normalize(&matrix.vy);
	vector_normalize(&matrix.vz);
	result = matrix_vector_product_stack(matrix, ray_direction);
	vector_normalize(&result);
	return (result);
}
