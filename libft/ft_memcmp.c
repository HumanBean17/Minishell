/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:53:02 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/11 19:02:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned const char *new_arr1;
	unsigned const char *new_arr2;

	if (n <= 0)
		return (0);
	new_arr1 = (unsigned const char *)arr1;
	new_arr2 = (unsigned const char *)arr2;
	while (n--)
	{
		if (*new_arr1 == *new_arr2)
		{
			new_arr1++;
			new_arr2++;
		}
		else
			return ((int)(*new_arr1 - *new_arr2));
	}
	return (0);
}
