/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:39:28 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/27 12:49:04 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_find(t_list *begin_list, int fd)
{
	t_list *tmp;

	tmp = begin_list;
	if (tmp)
	{
		while ((tmp->next) && ((size_t)fd != (tmp->content_size)))
			tmp = tmp->next;
		if (tmp->content_size == (size_t)fd)
			return (tmp);
	}
	return (NULL);
}
