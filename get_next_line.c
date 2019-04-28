/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 00:58:45 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/28 01:09:41 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int		find_char(const char *s, char c)
{
	int i;

	i = 0;
	if (!(s))
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int		read_file(t_list **file, int fd, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	int		sz;

	if ((read(fd, buffer, 0) < 0 || fd < 0 || !line))
		return (-1);
	while ((sz = read(fd, buffer, BUFF_SIZE)) && sz)
	{
		buffer[sz] = '\0';
		if (!((*file)->content = ft_strjoin((*file)->content, buffer)))
			return (-1);
		if ((ft_strchr(buffer, '\n')))
			break ;
	}
	if (sz == 0 && !ft_strlen((char *)(*file)->content))
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	static t_list	*file;
	t_list			*tmp;

	tmp = (t_list *)ft_memalloc(sizeof(t_list));
	tmp->content = ft_strnew(0);
	ft_lstinsert(&file, tmp);
	i = read_file(&file, fd, line);
	if (i != 1)
		return (i);
	i = 0;
	if (!ft_strchr(file->content, '\n'))
	{
		*line = ft_strdup(file->content);
		ft_strclr(file->content);
		return (1);
	}
	i = find_char(file->content, '\n');
	*line = ft_strsub(file->content, 0, i);
	file->content = ft_strchr(file->content, '\n') + 1;
	return (1);
}
