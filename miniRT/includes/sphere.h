/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:20:22 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

typedef struct s_sphere
{
	t_vector		*center;
	float			radius;
	unsigned int	hex_rgb;
}				t_sphere;

t_sphere	*sphere_new(t_vector *center, float radius,
				unsigned int hex_rgb);

t_bool		is_sphere_intersect(t_sphere *sphere, t_ray *ray);
t_bool		sphere_find_intersection(t_sphere *sphere, t_ray *ray);

#endif
