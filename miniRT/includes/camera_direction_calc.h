/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_direction_calc.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:39:09 by sserwyn           #+#    #+#             */
/*   Updated: 2022/08/01 23:08:16 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_DIRECTION_CALC_H
# define CAMERA_DIRECTION_CALC_H

typedef struct s_matrix
{
	t_vector	vx;
	t_vector	vy;
	t_vector	vz;
}	t_matrix;

t_vector	camera_direction_calc(t_camera camera, int x, int y);

#endif
