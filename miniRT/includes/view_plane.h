/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_plane.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:23:43 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 17:42:14 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_PLANE_H
# define VIEW_PLANE_H

typedef struct s_vplane
{
	float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
}				t_vplane;

t_vplane	*get_view_plane(float width, float height, \
							unsigned int fov_angle);
void		ray_tracing(t_mlx *mlx, \
						t_filtered_elements elements);

#endif
