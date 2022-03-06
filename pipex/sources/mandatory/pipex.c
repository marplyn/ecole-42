/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:38:13 by dground           #+#    #+#             */
/*   Updated: 2022/03/05 17:46:14 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "tools.h"

void	child_1_process(char **argv, char **envp, int *fd)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY, 0777);
	if (file1 == -1)
		ft_error();
	dup2(file1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	cmd_exec(argv[2], envp);
}

void	child_2_process(char **argv, char **envp, int *fd)
{
	int	file2;

	file2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (file2 == -1)
		ft_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(fd[1]);
	cmd_exec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	child1;
	pid_t	child2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error();
		child1 = fork();
		if (child1 == -1)
			ft_error();
		if (child1 == 0)
			child_1_process(argv, envp, fd);
		child2 = fork();
		if (child2 == -1)
			ft_error();
		if (child2 == 0)
			child_2_process(argv, envp, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(child1, NULL, 0);
		waitpid(child2, NULL, 0);
	}
	else
		ft_error();
}
