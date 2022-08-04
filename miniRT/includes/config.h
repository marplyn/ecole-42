/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:17:08 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 18:07:18 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
# define PBWIDTH 60

# define ESC_KEY_CODE 65307
# define WINDOW_NAME "miniRT"

# define WINDOW_WIDTH 400
# define WINDOW_HEIGHT 400

# define BLACK_COLOR 0x000000

# define EPSILON 1e-4

# define MALLOC_ERROR "Couldn't allocate memory."

typedef enum s_bool
{
	false,
	true
}			t_bool;

#endif
