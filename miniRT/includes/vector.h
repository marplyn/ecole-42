/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:26:28 by dground           #+#    #+#             */
/*   Updated: 2022/08/01 05:55:54 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}				t_vector;

t_vector	*vector_new(float x, float y, float z);
t_vector	*vector_subtract(t_vector *a, t_vector *b);
t_vector	*vector_add(t_vector *a, t_vector *b);
t_vector	*vector_scalar_multiple(t_vector *a, float b);

float		vector_length(t_vector *vector);
void		vector_normalize(t_vector *vector);
float		vector_dot_product(t_vector *a, t_vector *b);

t_vector	vector_add_stack(t_vector a, t_vector b);
t_vector	vector_subtract_stack(t_vector a, t_vector b);
t_vector	vector_scalar_multiple_stack(t_vector a, float b);

#endif
