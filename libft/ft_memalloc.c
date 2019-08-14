/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:14:03 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/11 19:02:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ar;

	ar = NULL;
	ar = malloc(size);
	if (ar)
	{
		ft_memset(ar, 0, size);
		return (ar);
	}
	return (NULL);
}
