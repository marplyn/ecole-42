/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:35:27 by dground           #+#    #+#             */
/*   Updated: 2022/07/31 23:36:06 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	read_description_file(int fd, t_list **elements,
	t_element_exists *element_exists)
{
	char	*line;

	line = NULL;
	while (1)
	{
		if (line != NULL)
			free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (line[0] == '\n' || line[0] == '\0')
			continue ;
		parsing(elements, line, element_exists);
	}
	free(line);
}

t_list	*init_scene_elements(char *file)
{
	t_list				*elements;
	int					fd;
	t_element_exists	element_exists;

	elements = NULL;
	element_exists.ambient_light = false;
	element_exists.camera = false;
	element_exists.light = false;
	element_exists.multi_ambient_light = false;
	element_exists.multi_light = false;
	is_rt_file(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		display_error_exit(READ_ERROR);
	read_description_file(fd, &elements, &element_exists);
	return (elements);
}
