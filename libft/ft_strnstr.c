/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:51:35 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/13 14:34:23 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int i;
	int j;
	int num;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && (n > 0))
	{
		j = 0;
		if (str[j + i] == to_find[j])
		{
			num = n;
			while (str[j + i] == to_find[j] && (num--))
			{
				if (j + 1 == (int)ft_strlen(to_find))
					return ((char *)(str + i));
				j++;
			}
		}
		n--;
		i++;
	}
	return (NULL);
}
