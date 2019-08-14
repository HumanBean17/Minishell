/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:22:45 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/24 12:49:33 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(const char content[], int fd)
{
	t_list *tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp)
	{
		if (content)
			tmp->content = ft_strdup(content);
		else
			tmp->content = NULL;
		tmp->content_size = (size_t)fd;
		tmp->next = NULL;
		return (tmp);
	}
	ft_lstdel(&tmp, ft_memdel);
	return (NULL);
}
