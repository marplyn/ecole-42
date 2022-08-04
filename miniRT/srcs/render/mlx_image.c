/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 06:43:33 by sserwyn           #+#    #+#             */
/*   Updated: 2022/08/01 07:52:08 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vplane	*get_view_plane(float width, float height,
							unsigned int fov_angle)
{
	t_vplane	*vplane;
	float		aspect_ratio;

	vplane = (t_vplane *)malloc(sizeof(t_vplane));
	if (!vplane)
		display_error_exit(MALLOC_ERROR);
	aspect_ratio = width / height;
	vplane->width = 2 * tanf(fov_angle / 2 * M_PI / 180);
	vplane->height = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->height / height;
	return (vplane);
}

t_mlx_img	mlx_img_new(t_mlx mlx, int width, int height)
{
	t_mlx_img	image;

	image.img = mlx_new_image(mlx.mlx_ptr, width, height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, \
		&image.line_length, &image.endian);
	return (image);
}
