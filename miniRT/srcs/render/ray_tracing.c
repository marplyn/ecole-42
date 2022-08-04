/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:09:01 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 23:42:45 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	mlx_my_put_pixel_to_img(t_mlx_img *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length
			+ x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	put_pixel(t_ray_tracing rt, t_filtered_elements elements, t_ray ray)
{
	if (ray.distance != INFINITY)
	{
		vector_normalize(&ray.normal);
		calculate_pixel_color(elements, &ray);
		if (ray.hex_rgb != BLACK_COLOR)
			mlx_my_put_pixel_to_img(&rt.image, rt.mlx_x, rt.mlx_y, \
									(int) ray.hex_rgb);
	}
}

static void	ray_tracing_logic(t_ray_tracing rt, t_filtered_elements elements)
{
	t_ray		ray;
	t_vector	ray_direction_from_camera;

	rt.y_ray = rt.y_angle * rt.vplane->y_pixel;
	rt.x_angle = -WINDOW_WIDTH / 2;
	rt.mlx_x = 0;
	while (rt.x_angle <= WINDOW_WIDTH / 2)
	{
		rt.x_ray = rt.x_angle * rt.vplane->x_pixel;
		print_progress_by_percent((float) rt.mlx_y / WINDOW_HEIGHT);
		ray_direction_from_camera = camera_direction_calc(*rt.camera, \
															rt.mlx_x, rt.mlx_y);
		vector_normalize(&ray_direction_from_camera);
		ray = ray_new(rt.camera->position, &ray_direction_from_camera);
		find_nearest_intersection(elements, &ray);
		put_pixel(rt, elements, ray);
		rt.x_angle++;
		rt.mlx_x++;
	}
}

void	ray_tracing(t_mlx *mlx, t_filtered_elements elements)
{
	t_ray_tracing	rt;

	rt.image = mlx_img_new(*mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	rt.camera = elements.cameras->content;
	rt.vplane = get_view_plane(\
		WINDOW_WIDTH, WINDOW_HEIGHT, rt.camera->fov_angle);
	rt.y_angle = WINDOW_HEIGHT / 2;
	rt.mlx_y = 0;
	while (rt.y_angle >= -WINDOW_HEIGHT / 2)
	{
		ray_tracing_logic(rt, elements);
		rt.y_angle--;
		rt.mlx_y++;
	}
	printf("\n");
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			WINDOW_NAME);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, rt.image.img, 0, 0);
	elements.cameras = elements.cameras->next;
	free(rt.vplane);
}
