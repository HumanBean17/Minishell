/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:10:51 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/11 19:02:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new_s;
	size_t	size;

	if (s)
	{
		i = 0;
		new_s = NULL;
		size = ft_strlen(s);
		new_s = ft_strnew(size);
		if (new_s)
		{
			while (s[i] != '\0')
			{
				new_s[i] = f(i, s[i]);
				i++;
			}
			return (new_s);
		}
	}
	return (NULL);
}
