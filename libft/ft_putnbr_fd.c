/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:40 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/13 14:41:37 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char					*ft_strrev(char *str)
{
	int i;
	int k;

	i = 0;
	k = 0;
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

void						ft_putnbr_fd(int n, int fd)
{
	unsigned long int	num;
	int					i;
	char				c[20];

	i = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	num = (unsigned long int)n;
	while (num > 0)
	{
		c[i++] = (char)(num % 10 + 48);
		num /= 10;
	}
	c[i] = '\0';
	ft_putstr_fd(ft_strrev(c), fd);
}
