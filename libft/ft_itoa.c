/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:25:02 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/11 19:02:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_num_len(int n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*ft_strrev(char *str, int flag)
{
	int i;
	int k;

	i = (flag == -1) ? 1 : 0;
	k = (flag == -1) ? 1 : 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (i > k)
	{
		str[k] += str[i];
		str[i] = str[k] - str[i];
		str[k] -= str[i];
		k++;
		i--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char				*num;
	int					len;
	int					i;
	int					flag;
	unsigned long int	l;

	l = (unsigned long int)n;
	i = 0;
	flag = n < 0 ? -1 : 1;
	l *= (unsigned long int)flag;
	len = ft_num_len(l) + 1;
	num = ft_strnew(len);
	if (flag == 1)
		num[len] = '\0';
	if (!num)
		return (NULL);
	num[0] = '0';
	while (l > 0)
	{
		if (flag == -1 && i == 0)
			num[i++] = '-';
		num[i++] = (char)((l % 10) + 48);
		l /= 10;
	}
	return (ft_strrev(num, flag));
}
