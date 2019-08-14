/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <lcrawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:01:25 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/13 16:49:11 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char		*s;
	unsigned char		l;

	if (n <= 0)
		return (NULL);
	l = (unsigned char)c;
	s = (unsigned char *)arr;
	while (n--)
	{
		if (*s != l)
			s++;
		else
			return (s);
	}
	return (NULL);
}
