/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:39:28 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/23 18:31:49 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_find(t_list *begin_list, int des)
{
	t_list *tmp;

	tmp = begin_list;
	if (tmp)
	{
		while ((tmp->next) && ((size_t)des != (tmp->content_size)))
			tmp = tmp->next;
		if (tmp->content_size == des)
			return (tmp);
	}
	return (NULL);
}
