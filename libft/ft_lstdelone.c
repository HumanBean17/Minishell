/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:21:00 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/27 17:56:54 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **begin, t_list *to_del)
{
	t_list	*tmp;
	t_list	*cp;

	tmp = *begin;
	if (!tmp || !to_del)
		return ;
	if (tmp == to_del)
	{
		*begin = tmp->next;
		ft_lstdel(&tmp);
		return ;
	}
	while (tmp->next != to_del)
		tmp = tmp->next;
	cp = tmp->next;
	if (tmp->next != NULL && (tmp->next)->next == NULL)
	{
		tmp->next = NULL;
		ft_lstdel(&cp);
	}
	else
	{
		tmp->next = (tmp->next)->next;
		ft_lstdel(&cp);
	}
}
