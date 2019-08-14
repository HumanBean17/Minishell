/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <lcrawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:50:19 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/11 19:02:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *app, size_t n)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (dst[i] != '\0')
		i++;
	while (app[k] != '\0' && (n--))
	{
		dst[i] = app[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (dst);
}
