/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <lcrawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:50:10 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/11 19:02:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	k;

	i = 0;
	k = (unsigned char)c;
	while (s[i] != '\0')
	{
		if ((unsigned const char)s[i] == k)
			return ((char *)(s + i));
		i++;
	}
	if ((unsigned const char)s[i] == k)
		return ((char *)(s + i));
	else
		return (NULL);
}
