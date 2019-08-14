/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:56:46 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/11 19:02:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	l;
	char			*ptr;

	l = (unsigned char)c;
	i = 0;
	ptr = NULL;
	while (str[i] != '\0')
	{
		if ((unsigned const char)str[i] == l)
			ptr = (char *)(str + i);
		i++;
	}
	if ((unsigned const char)str[i] == l)
		return ((char *)(str + i));
	else if (ptr)
		return (ptr);
	return (NULL);
}
