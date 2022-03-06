/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:31:38 by dground           #+#    #+#             */
/*   Updated: 2022/03/05 17:48:10 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "tools.h"

void	ft_error_bonus(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

char	*path_parsing_bonus(char *command, char **envp)
{
	char	**mypaths;
	char	*onepath;
	char	*fullpath;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	mypaths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (mypaths[i])
	{
		onepath = ft_strjoin(mypaths[i], "/");
		fullpath = ft_strjoin(onepath, command);
		free(onepath);
		if (access(fullpath, F_OK) == 0)
			return (fullpath);
		i++;
	}
	return (0);
}

void	cmd_exec_bonus(char *argv, char **envp)
{
	char	**command;
	char	*path;

	command = ft_split(argv, ' ');
	path = path_parsing_bonus(command[0], envp);
	if (execve(path, command, envp) == -1)
		ft_error_bonus();
}

int	simple_gnl(char **line)
{
	int		i;
	int		rd;
	char	ch;
	char	*buffer;

	i = 0;
	buffer = (char *)malloc(sizeof(char) * 1024);
	if (!buffer)
		return (-1);
	rd = read(0, &ch, 1);
	while (rd > 0 && ch != '\n')
	{
		buffer[i] = ch;
		i++;
		rd = read(0, &ch, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (rd);
}

int	file_processing(char *argv, int c)
{
	int	file;

	file = 0;
	if (c == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (c == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (c == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		ft_error_bonus();
	return (file);
}
