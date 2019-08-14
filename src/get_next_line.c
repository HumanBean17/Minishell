#include "get_next_line.h"

void f(int c_size)
{

	printf("(%i) ", c_size);
}

void ft_lstprint(t_list **alst, void (*print)(int c_size))
{
	t_list *iter;

	if (!alst || !print)
		return ;
	if (!*alst)
	{
		printf("List is empty\n");
		return ;
	}
	iter = *alst;
	while (iter)
	{
		print(iter->content_size);
		if (iter->next)
			printf(" -> ");
		iter = iter->next;
	}
	printf("\n");
}

static int ft_end_len(const char *ar)
{
	int len;

	len = 0;
	while (ar[len] != '\n' && ar[len] != '\0')
		len++;
	return (len);
}

static int ft_call(void **content, char **line, t_list **alst, t_list *tmp)
{
	char *s;

	*line = ft_strsub(*content, 0, ft_end_len(*content));
	if (ft_end_len(*content) == (int)ft_strlen(*content))
	{
		ft_lstdelone(alst, tmp, ft_memdel);
		return (1);
	}
	s = ft_strsub(*content, ft_end_len(*content) + 1, ft_strlen(*content));
	ft_memdel(content);
	*content = ft_strdup(s);
	ft_strdel(&s);
	return (1);
}

static void		ft_content_join(t_list **list, char buf[])
{
	char *s;

	if ((*list)->content)
	{
		s = ft_strdup((*list)->content);
		ft_memdel(&((*list)->content));
		(*list)->content = ft_strjoin(s, buf);
		ft_strdel(&s);
		return ;
	}
	s = ft_strnew(1);
	ft_memdel(&((*list)->content));
	(*list)->content = ft_strjoin(s, buf);
	ft_strdel(&s);
}

int 		get_next_line(const int fd, char **line)
{
	int 			ret;
	static t_list 	*list;
	t_list 			*tmp;
	char 			buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if (!ft_list_find(list, fd))
			ft_list_push_back(&list, NULL, fd);
		tmp = ft_list_find(list, fd);
		ft_content_join(&tmp, buf);
		if (buf[ft_end_len(buf)] == '\n')
		{
			ft_call(&(tmp->content), line, &list, tmp);
			return (1);
		}
	}
	if ((tmp = ft_list_find(list, fd)))
	{
		ft_call(&(tmp->content), line, &list, tmp);
		return (1);
	}
	return (0);
}

