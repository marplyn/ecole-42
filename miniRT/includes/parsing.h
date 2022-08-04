/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:25:13 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

t_list			*init_scene_elements(char *file);

void			parsing(t_list **elements, char *line,
					t_element_exists *element_exists);

unsigned int	parse_colors(char *array);
t_vector		*parse_coordinates(char *array);
t_vector		*parse_vector(char *array);

void			parse_objects(t_list **elements, char **splitted_line);
void			parse_sphere(t_list **elements, char **array);
void			parse_plane(t_list **elements, char **array);
void			parse_cylinder(t_list **elements, char **splitted_line);

#endif