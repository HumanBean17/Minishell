/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:54:58 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/11 18:21:49 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	if (n <= 0)
		return (0);
	i = 0;
	while ((s1[i] == s2[i]) &&
	s1[i] != '\0' && s2[i] != '\0' && (--n))
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
