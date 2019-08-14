/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <lcrawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:31:45 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/11 19:02:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char		*dst;
	unsigned const char	*src;
	unsigned char		new_c;

	if (n <= 0)
		return (NULL);
	new_c = (unsigned char)c;
	dst = (unsigned char *)destination;
	src = (unsigned const char *)source;
	while (n--)
	{
		if (*src != new_c)
			*dst++ = *src++;
		else
		{
			*dst = *src;
			return (dst + 1);
		}
	}
	return (NULL);
}
