/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 00:58:45 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/30 01:09:59 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static int		find_char(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return ((s[i] == c) ? i : 0);
}

static t_list	*handle_file(t_list **file, int fd)
{
	t_list *p;

	p = *file;
	while (p)
	{
		if ((int)p->content_size == fd)
			return (p);
		p = p->next;
	}
	p = ft_lstnew("\0", fd);
	ft_lstadd(file, p);
	p = *file;
	return (p);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	char			buffer[BUFF_SIZE + 1];
	int				sz;
	t_list			*node;

	RETURN_IF((read(fd, NULL, 0) < 0 || fd < 0 || !line), -1);
	node = handle_file(&file, fd);
	while ((sz = read(fd, buffer, BUFF_SIZE)) && sz)
	{
		buffer[sz] = '\0';
		node->content = ft_strjoin(node->content, buffer);
		if ((ft_strchr(node->content, '\n')))
			break ;
	}
	RETURN_IF((sz == 0 && !ft_strlen((char *)node->content)), 0);
	if (!ft_strchr(node->content, '\n'))
	{
		*line = ft_strdup(node->content);
		ft_strclr(file->content);
		return (1);
	}
	*line = ft_strsub(node->content, 0, find_char(node->content, '\n'));
	node->content = ft_strchr(node->content, '\n') + 1;
	return (1);
}
