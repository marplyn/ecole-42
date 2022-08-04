/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:39:48 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

unsigned int	rgb_to_hex(unsigned int r, unsigned int g, unsigned int b)
{
	return (r << 16 | g << 8 | b);
}

unsigned int	get_r_from_hex(unsigned int hex_rgb)
{
	unsigned int	result;

	result = (hex_rgb & (255 << 16));
	return (result >> 16);
}

unsigned int	get_g_from_hex(unsigned int hex_rgb)
{
	unsigned int	result;

	result = (hex_rgb & (255 << 8));
	return (result >> 8);
}

unsigned int	get_b_from_hex(unsigned int hex_rgb)
{
	return (hex_rgb & 255);
}
