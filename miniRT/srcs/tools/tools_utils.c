/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:35:21 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 07:02:41 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	display_error_exit(char *message)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\nError\n", 2);
	exit(EXIT_FAILURE);
}

void	print_progress_by_percent(float percentage)
{
	int	val;
	int	lpad;
	int	rpad;

	val = (int)(percentage * 100);
	if (val % 10 != 0)
		return ;
	lpad = (int)(percentage * PBWIDTH);
	rpad = PBWIDTH - lpad;
	printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
}

void	clear_scene_2(t_list *tmp)
{
	if (((t_scene_element *)tmp->content)->type == SPHERE)
	{
		free(((t_sphere *)((t_scene_element *)tmp->content)->data)->center);
		free(((t_sphere *)((t_scene_element *)tmp->content)->data));
	}
	else if (((t_scene_element *)tmp->content)->type == PLANE)
	{
		free(((t_plane *)((t_scene_element *)tmp->content)->data)->normal);
		free(((t_plane *)((t_scene_element *)tmp->content)->data)->point);
		free(((t_plane *)((t_scene_element *)tmp->content)->data));
	}
	else if (((t_scene_element *)tmp->content)->type == CYLINDER)
	{
		free(((t_cylinder *)((t_scene_element *)
					tmp->content)->data)->normal);
		free(((t_cylinder *)((t_scene_element *)
					tmp->content)->data)->point);
		free(((t_cylinder *)((t_scene_element *)tmp->content)->data));
	}
}

void	clear_scene(t_list **scene_elements)
{
	t_list	*tmp;

	tmp = *scene_elements;
	while (tmp)
	{
		if (((t_scene_element *)tmp->content)->type == AMBIENT_LIGHTNING)
			free(((t_scene_element *)tmp->content)->data);
		else if (((t_scene_element *)tmp->content)->type == CAMERA)
		{
			free(((t_camera *)((t_scene_element *)
						tmp->content)->data)->position);
			free(((t_camera *)((t_scene_element *)
						tmp->content)->data)->direction);
			free(((t_camera *)((t_scene_element *)tmp->content)->data));
		}
		else if (((t_scene_element *)tmp->content)->type == LIGHT)
		{
			free(((t_light *)((t_scene_element *)tmp->content)->data)->center);
			free(((t_light *)((t_scene_element *)tmp->content)->data));
		}
		clear_scene_2(tmp);
		tmp = tmp->next;
	}
	ft_lstclear(scene_elements, free);
}
