/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:13:38 by nabdelba          #+#    #+#             */
/*   Updated: 2019/04/24 17:13:38 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static int find_char(const char *s,char c)
{
	char *p;
	p = (char *)s;
	while (*s)
		if(*s++ == c)
			return (s - p);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int sz;
	char buffer[BUFFER_SIZE];
	static t_list *file;
	t_list *tmp;
	tmp = (t_list *)ft_memalloc(sizeof(t_list));
	tmp->content = ft_strnew(0);
	ft_lstinsert(&file,tmp);
	char *p;
	int i;
	while ((sz = read(fd, buffer, BUFFER_SIZE)) && sz)
	{
		buffer[sz] = '\0';
		file->content = ft_strjoin(file->content,buffer);
		if((i = find_char(buffer,'\n')) && i)
		{
			break;	
		}
	}
	i = find_char(file->content,'\n');
	p = ft_strsub(file->content,0,i);
	file->content = ft_strchr(file->content,'\n') + 1;
	printf("%s",p);
	return (0);
}

int main()
{
	int fd;
	fd = open("test.opt",O_RDONLY);
	char *line;
	get_next_line(fd,&line);
	//get_next_line(fd,&line);
	//get_next_line(fd,&line);
	//get_next_line(fd,&line);

}


































