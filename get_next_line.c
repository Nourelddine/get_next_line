/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 00:58:45 by nabdelba          #+#    #+#             */
/*   Updated: 2019/05/02 22:56:21 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

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
	p = malloc(sizeof(t_list));
	p->content = ft_strnew(0);
	p->content_size = fd;
	ft_lstadd(file, p);
	p = *file;
	return (p);
}

static void		read_file(t_list **node, int fd, int *sz, char **tmp)
{
	char	buffer[BUFF_SIZE];

	while ((*sz = read(fd, buffer, BUFF_SIZE)) && *sz)
	{
		buffer[*sz] = '\0';
		*tmp = ft_strnew(ft_strlen((char *)(*node)->content));
		ft_strcpy(*tmp, (*node)->content);
		(*node)->content = ft_strjoin(*tmp, buffer);
		free(*tmp);
		if ((ft_strchr((*node)->content, '\n')))
			break ;
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	int				sz;
	t_list			*node;
	char			*tmp;

	sz = 0;
	RETURN_IF((read(fd, NULL, 0) < 0 || fd < 0 || !line), -1);
	node = handle_file(&file, fd);
	read_file(&node, fd, &sz, &tmp);
	RETURN_IF((sz == 0 && !ft_strlen((char *)node->content)), 0);
	if (!ft_strchr(node->content, '\n'))
	{
		*line = ft_strdup(node->content);
		ft_strclr(file->content);
		return (1);
	}
	*line = ft_strsub(node->content, 0, ft_findchr(node->content, '\n'));
	tmp = ft_strnew(ft_strlen((char *)node->content));
	ft_strcpy(tmp, node->content);
	free(node->content);
	node->content = ft_strdup(ft_strchr(tmp, '\n') + 1);
	free(tmp);
	return (1);
}
