/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:15:59 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define ARGS_ERROR "Wrong number of arguments."
# define FILE_EXTENTION_ERROR "Not a .rt file."
# define READ_ERROR "Couldn't read file."
# define PARSE_ERROR "Couldn't parse file."
# define ELEMENT_PARAMS_ERROR "Wrong element's information."

void	print_progress_by_percent(float percentage);
void	display_error_exit(char *message);
float	*solve_quadratic_equation(float a, float b, float c);
void	is_rt_file(char *filename);
int		ft_arraylen(char **array);
void	ft_free_array(char **array);
char	*check_float_str(char *str);
char	*check_int_str(char *str);
void	clear_scene(t_list **scene_elements);

#endif
