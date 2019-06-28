/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 00:58:45 by nabdelba          #+#    #+#             */
/*   Updated: 2019/06/28 09:40:13 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"


static t_list	*handle_file(t_list **list,int fd)
{
	t_list *tmp;
	tmp  = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("",fd);
	ft_lstadd(list, tmp);
	return (tmp);
}


int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	int				sz;
	t_list			*node;
	char buff[BUFF_SIZE + 1];
	char *tmp;
	char *t;

	RETURN_IF((read(fd, NULL, 0) < 0 || fd < 0 || !line), -1);
	node = handle_file(&file, fd);
	
	while (( sz = read(fd,buff,BUFF_SIZE)) && sz != 0)
	{
		buff[sz] = '\0';
		tmp = ft_strnew(ft_strlen(node->content));
		ft_strcpy(tmp, (char *)node->content);
		t = node->content;
		node->content = ft_strjoin(tmp,buff);
		free(t);
		free(tmp);
		if (ft_strchr((char *)node->content, '\n'))
			break;
	}
	if (!ft_strlen((char *)node->content) && sz == 0)
		return (0);
	if (!ft_strchr(node->content,'\n') && ft_strlen((char *)node->content))
	{
		RETURN_IF(!(*line = ft_strdup(node->content)),0);
		ft_strclr(node->content);
		return (1);
	}
	RETURN_IF(!(*line = ft_strsub(node->content,0,
				(ft_strchr(node->content,'\n') - (char *)node->content))),0);
	node->content = ft_strchr(node->content,'\n') + 1;
	return (1);
}






















/*
*/