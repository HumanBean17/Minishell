/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <lcrawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:20:59 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/11 19:02:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*src;
	unsigned char		*src_1;
	int					i;

	i = 0;
	dst = (unsigned char *)destination;
	src = (unsigned const char *)source;
	src_1 = (unsigned char *)malloc(sizeof(unsigned char) * n + 1);
	if (!src_1)
		return (destination);
	while (i < (int)n)
	{
		src_1[i] = *(src++);
		i++;
	}
	src_1[i] = '\0';
	i = 0;
	while (n--)
	{
		*(dst++) = src_1[i];
		i++;
	}
	return (destination);
}
