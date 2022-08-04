/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:22:21 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

unsigned int	rgb_to_hex(unsigned int r, unsigned int g, unsigned int b);
unsigned int	get_r_from_hex(unsigned int hex_rgb);
unsigned int	get_g_from_hex(unsigned int hex_rgb);
unsigned int	get_b_from_hex(unsigned int hex_rgb);
unsigned int	hex_rgb_apply_brightness(unsigned int hex_rgb,
					float brightness);
unsigned int	hex_rgb_add(unsigned int hex_rgb1, unsigned int hex_rgb2);

#endif
