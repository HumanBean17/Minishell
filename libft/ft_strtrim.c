/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:20:00 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/11 19:02:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		left_space(const char *s, int i)
{
	while ((s[i] == '\n' || s[i] == '\t' || s[i] == ' ') && s[i] != '\0')
		i++;
	return (i);
}

static int		right_space(const char *s, int size)
{
	while ((s[size] == '\n' || s[size] == '\t' || s[size] == ' ') && size != 0)
		size--;
	return (size);
}

char			*ft_strtrim(char const *s)
{
	char	*new_s;
	int		i;
	int		j;
	int		size;
	int		len;

	if (s)
	{
		j = 0;
		i = 0;
		size = ft_strlen(s) - 1;
		i = left_space(s, i);
		len = right_space(s, size) - i + 1;
		if (len < 0)
			len *= 0;
		new_s = ft_strnew(len);
		if (new_s)
		{
			while ((len--))
				new_s[j++] = s[i++];
			return (new_s);
		}
	}
	return (NULL);
}
