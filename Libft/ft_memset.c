/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:29:33 by dground           #+#    #+#             */
/*   Updated: 2021/10/04 16:29:36 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*p;

	*p = b;
	i = 0;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (b);
}

int main(void)
{
	char *str;

	str = strdup("hello");
	printf("%d%d\n", ft_memset((void *)str, 'a', 5), memset((void *)str, 'a', 5));
}