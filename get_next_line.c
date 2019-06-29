/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 00:58:45 by nabdelba          #+#    #+#             */
/*   Updated: 2019/06/29 03:13:00 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static t_list		*handle_file(t_list **list, int fd)
{
	t_list			*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(list, tmp);
	return (tmp);
}

static int			read_file(char **tmp, t_list **file, int fd, int *sz)
{
	char			buff[BUFF_SIZE + 1];

	while ((*sz = read(fd, buff, BUFF_SIZE)) && *sz != 0)
	{
		buff[*sz] = '\0';
		*tmp = ft_strdup((char *)(*file)->content);
		free((*file)->content);
		RETURN_IF(!((*file)->content = ft_strjoin(*tmp, buff)), 0);
		free(*tmp);
		if (ft_strchr((char *)(*file)->content, '\n'))
			break ;
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*file;
	int				sz;
	t_list			*node;
	char			*tmp;

	RETURN_IF((read(fd, NULL, 0) < 0 || fd < 0 || !line), -1);
	node = handle_file(&file, fd);
	RETURN_IF(!(read_file(&tmp, &node, fd, &sz)), -1);
	if (!ft_strlen((char *)node->content) && sz == 0)
		return (0);
	if (!ft_strchr(node->content, '\n') && ft_strlen((char *)node->content))
	{
		RETURN_IF(!(*line = ft_strdup(node->content)), 0);
		ft_strclr(node->content);
		return (1);
	}
	tmp = ft_strdup(node->content);
	RETURN_IF(!(*line = ft_strsub(tmp, 0, (ft_strchr(tmp, '\n') - tmp))), 0);
	free(node->content);
	node->content = ft_strdup(ft_strchr(tmp, '\n') + 1);
	free(tmp);
	return (1);
}
