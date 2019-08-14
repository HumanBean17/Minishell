/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <lcrawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:34:19 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/11 19:02:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cp_str;
	int		i;

	i = 0;
	cp_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (cp_str)
	{
		while (str[i] != '\0')
		{
			cp_str[i] = str[i];
			i++;
		}
		cp_str[i] = '\0';
	}
	return (cp_str);
}
