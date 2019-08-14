/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:31:42 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/24 12:44:25 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_back(t_list **begin_list, const char content[], int fd)
{
	t_list *tmp;

	tmp = *begin_list;
	if (tmp == 0)
	{
		tmp = ft_lstnew(content, fd);
		*begin_list = tmp;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_lstnew(content, fd);
}
