/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:26:00 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 22:44:33 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../get_next_line/get_next_line.h"

# include "config.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx_structs.h"
# include <fcntl.h>
# include "vector.h"
# include "utils.h"
# include "ray.h"
# include "color.h"
# include "camera.h"
# include "sphere.h"
# include "light.h"
# include "ambient_light.h"

# include "hooks.h"
# include "scene_element.h"
# include "view_plane.h"
# include "plane.h"
# include "intersection.h"
# include "cylinder.h"
# include "calculate_pixel_color.h"
# include "ray_tracing_struct.h"
# include "camera_direction_calc.h"

# include "parsing.h"

#endif
