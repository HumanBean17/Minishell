/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:58:32 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/27 18:03:27 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_end_len(const char buf[])
{
	int len;

	len = 0;
	while (buf[len] != '\n' && buf[len] != '\0')
		len++;
	if (buf[len] == '\n' || buf[len] == '\0')
		return (len);
	return (0);
}

static void		ft_content_join(void **content, char buf[])
{
	char *s;

	if (!(*content))
	{
		*content = ft_strjoin(NULL, buf);
		return ;
	}
	s = ft_strdup(*content);
	ft_memdel(content);
	*content = ft_strjoin(s, buf);
	ft_strdel(&s);
}

static int		ft_call(t_list **begin, t_list *tmp, char **line)
{
	char	*s;
	int		len;

	s = ft_strdup(tmp->content);
	len = s[0] == '\n' ? ft_end_len(s + 1) : ft_end_len(s);
	*line = s[0] == '\n' ? ft_strsub(s, 1, len) : ft_strsub(s, 0, len);
	if (s[1] == '\0' || s[0] == '\0')
	{
		ft_strdel(&s);
		ft_lstdelone(begin, tmp);
		return (0);
	}
	ft_memdel(&(tmp->content));
	tmp->content = s[0] == '\n' ? ft_strsub(s, len + 1,
			ft_strlen(s)) : ft_strsub(s, len, ft_strlen(s));
	ft_strdel(&s);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	t_list			*tmp;
	static t_list	*list;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if (!ft_list_find(list, fd))
			ft_list_push_back(&list, fd);
		tmp = ft_list_find(list, fd);
		ft_content_join(&(tmp->content), buf);
		if (buf[ft_end_len(buf)] == '\n')
			break ;
	}
	if ((tmp = ft_list_find(list, fd)))
	{
		if (ft_call(&list, tmp, line) == 1)
			return (1);
	}
	return (0);
}
