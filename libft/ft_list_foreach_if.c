/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:11:08 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/14 17:19:58 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_foreach_if(t_list *begin_list,
		void (*f)(void *),
		void *content,
		int (*cmp)(void *, void *))
{
	t_list *tmp;

	tmp = begin_list;
	while (tmp != 0)
	{
		if (cmp(tmp->content, content) == 0)
			f(tmp->content);
		tmp = tmp->next;
	}
}
