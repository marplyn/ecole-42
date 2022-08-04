/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:18:42 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

typedef struct s_light
{
	t_vector		*center;
	float			brightness;
	unsigned int	hex_rgb;
}				t_light;

t_light			*light_new(t_vector *center, float brightness,
					unsigned int hex_rgb);
float			calculate_light_intensity(t_vector *normal,
					t_vector *shadow_direction, t_light *light);
unsigned int	calculate_light_color(t_light *light, unsigned int hex_rgb);

#endif
