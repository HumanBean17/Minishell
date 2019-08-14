/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:38:00 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/11 19:02:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					i;
	unsigned long int	c;
	int					flag;

	flag = 1;
	c = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		flag = (str[i] == '-') ? -1 : 1;
		i++;
	}
	if (str[i] < 48 || str[i] > 57)
		return (0);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		c = (c * 10) + ((int)str[i++] - 48);
		if (c >= 9223372036854775807 && flag == 1)
			return (-1);
		if (c > 9223372036854775807 && flag == -1)
			return (0);
	}
	return (c * (unsigned long int)flag);
}
