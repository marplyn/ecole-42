/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:24:10 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_LIGHT_H
# define AMBIENT_LIGHT_H

typedef struct s_ambient_light
{
	float			brightness;
	unsigned int	hex_rgb;
}				t_ambient_light;

t_ambient_light	*ambient_light_new(float brightness, unsigned int hex_rgb);

float			calculate_ambient_intensity(t_list *ambient_lights);
unsigned int	calculate_ambient_color(t_list *ambient_lights,
					unsigned int hex_rgb);

#endif
