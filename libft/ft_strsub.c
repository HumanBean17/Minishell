/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:15:53 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/11 19:02:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*new_s;

	if (s)
	{
		i = 0;
		new_s = NULL;
		new_s = ft_strnew(len);
		if (new_s)
		{
			while (s[start] != '\0' && len > 0)
			{
				new_s[i] = s[start];
				start++;
				i++;
				len--;
			}
			return (new_s);
		}
	}
	return (NULL);
}
