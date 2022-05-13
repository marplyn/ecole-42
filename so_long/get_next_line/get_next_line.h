/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:34:08 by dground           #+#    #+#             */
/*   Updated: 2022/05/03 21:38:58 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read_before_newline(int fd, char *leftover);
char	*ft_line_from_leftover(char *leftover);
char	*ft_trim_leftover(char *leftover);
size_t	ft_sl_gnl(char *str);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *leftover, char *buff);
char	*ft_strcat_gnl(char *str, char *buff);
char	*ft_strcpy_gnl(char *str, char *leftover);

#endif