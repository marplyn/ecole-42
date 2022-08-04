/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 06:51:22 by sserwyn           #+#    #+#             */
/*   Updated: 2022/08/01 07:51:25 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACING_STRUCT_H
# define RAY_TRACING_STRUCT_H

typedef struct s_ray_tracing
{
	int			mlx_x;
	int			mlx_y;
	float		x_angle;
	float		y_angle;
	float		x_ray;
	float		y_ray;
	t_vplane	*vplane;
	t_mlx_img	image;
	t_camera	*camera;
}				t_ray_tracing;

#endif
