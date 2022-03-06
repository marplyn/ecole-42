/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:30:36 by dground           #+#    #+#             */
/*   Updated: 2022/03/05 17:41:23 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

void	here_doc_processing(char *limiter, int argc);
int		file_processing(char *argv, int c);
int		simple_gnl(char **line);
void	cmd_exec_bonus(char *argv, char **envp);
char	*path_parsing_bonus(char *command, char **envp);
void	ft_error_bonus(void);
void	child_process_bonus(char *argv, char **envp);

#endif