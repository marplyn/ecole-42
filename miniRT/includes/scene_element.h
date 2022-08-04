/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_element.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:24:50 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_ELEMENT_H
# define SCENE_ELEMENT_H

typedef enum e_scene_element_type
{
	AMBIENT_LIGHTNING,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
}	t_scene_element_type;

typedef struct s_filtered_elements
{
	t_list	*ambient_lights;
	t_list	*cameras;
	t_list	*lights;
	t_list	*spheres;
	t_list	*planes;
	t_list	*cylinders;
}				t_filtered_elements;

typedef struct s_scene_element
{
	t_scene_element_type	type;
	void					*data;
}				t_scene_element;

typedef struct s_element_exists
{
	t_bool	ambient_light;
	t_bool	camera;
	t_bool	light;
	t_bool	multi_ambient_light;
	t_bool	multi_light;
}	t_element_exists;

t_scene_element		*scene_element_new(t_scene_element_type type, void *data);
t_list				*filter_scene_elements(t_list *scene_elements,
						t_scene_element_type type);
t_filtered_elements	filtered_elements_new(t_list *scene_elements);

#endif
