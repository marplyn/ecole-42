/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:01:33 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	esc_key_hook(int keycode, t_list *scene_elements)
{
	if (keycode == ESC_KEY_CODE)
	{
		clear_scene(&scene_elements);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static int	cross_close_button(t_list *scene_elements)
{
	clear_scene(&scene_elements);
	exit(EXIT_SUCCESS);
	return (0);
}

void	register_all_hooks(t_mlx mlx, t_list *scene_elements)
{
	mlx_key_hook(mlx.win_ptr, esc_key_hook, scene_elements);
	mlx_hook(mlx.win_ptr, 17, 0, cross_close_button, scene_elements);
}
