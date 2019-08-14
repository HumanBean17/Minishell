/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <lcrawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:56:47 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/11 19:02:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	dst_size;
	size_t	sum;
	int		c;

	i = 0;
	sum = 0;
	while (dst[sum] && sum < size)
		sum++;
	dst_size = ft_strlen(dst);
	c = size - dst_size - 1;
	while (c > 0 && (src[i] != '\0'))
	{
		dst[dst_size] = src[i];
		dst_size++;
		c--;
		i++;
		dst[dst_size] = '\0';
	}
	return (sum + ft_strlen(src));
}
