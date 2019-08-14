/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:21:00 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/26 18:43:45 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstdelone(t_list **alst, t_list *to_del, void (*del)(void **))
{
	t_list    *tmp;
	t_list    *cp;

	tmp = *alst;
	if (!tmp || !to_del)
		return ;
	if (tmp == to_del)
	{
		*alst = tmp->next;
		ft_lstdel(&tmp, del);
		return ;
	}
	while(tmp->next != to_del)
		tmp = tmp->next;
	if (tmp->next != NULL && (tmp->next)->next == NULL)
	{
		tmp->next = NULL;
		ft_lstdel(&tmp, del);
	}
	else
	{
		cp = tmp->next;
		tmp->next = (tmp->next)->next;
		ft_lstdel(&cp, del);
	}
}
