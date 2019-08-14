/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:30:18 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/14 17:17:38 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *tmp;
	t_list *list;
	t_list *n;

	tmp = 0;
	list = *begin_list;
	while (list != 0)
	{
		n = list->next;
		list->next = tmp;
		tmp = list;
		list = n;
	}
	*begin_list = tmp;
}
