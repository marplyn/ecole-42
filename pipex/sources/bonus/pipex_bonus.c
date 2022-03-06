/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:31:33 by dground           #+#    #+#             */
/*   Updated: 2022/03/05 17:46:26 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "tools.h"

void	child_process_bonus(char *argv, char **envp)
{
	int		fd[2];
	pid_t	child;

	if (pipe(fd) == -1)
		ft_error_bonus();
	child = fork();
	if (child == -1)
		ft_error_bonus();
	if (child == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		cmd_exec_bonus(argv, envp);
	}
	else
	{
		waitpid(child, NULL, 0);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
	}
}

void	here_doc_processing(char *limiter, int argc)
{
	pid_t	child;
	int		fd[2];
	char	*line;

	if (argc < 6)
		ft_error_bonus();
	if (pipe(fd) == -1)
		ft_error_bonus();
	child = fork();
	if (child == 0)
	{
		close(fd[0]);
		while (simple_gnl(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}	
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	file1;
	int	file2;
	int	i;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			file2 = file_processing(argv[argc - 1], 0);
			here_doc_processing(argv[2], argc);
		}
		else
		{
			i = 2;
			file2 = file_processing(argv[argc - 1], 1);
			file1 = file_processing(argv[1], 2);
			dup2(file1, STDIN_FILENO);
		}
		while (i < argc - 2)
			child_process_bonus(argv[i++], envp);
		dup2(file2, STDOUT_FILENO);
		cmd_exec_bonus(argv[argc - 2], envp);
	}
	ft_error_bonus();
}
