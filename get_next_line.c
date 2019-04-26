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
	s -= 1;
	while (*++s)
		if(*s == c || *s + 1 == c)
		{
			return (s - p);
		}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int sz;
	char buffer[BUFFER_SIZE + 1];
	static t_list *file;
	t_list *tmp;
	char *p;
	int i;

	if(read(fd,buffer,0) < 0 || fd < 0)
		return (-1);
	tmp = (t_list *)ft_memalloc(sizeof(t_list));
	tmp->content = ft_strnew(0);
	ft_lstinsert(&file,tmp);
	while ((sz = read(fd, buffer, BUFFER_SIZE)) && sz)
	{
		buffer[sz + 1] = '\0';
		file->content = ft_strjoin(file->content,buffer);
		if((find_char(buffer,'\n')))
			break;
	}
	i = find_char(file->content,'\n');
	p = ft_strsub(file->content,0,i);
	file->content = ft_strchr(file->content,'\n') + 1;
	*line = p;
	return (1);
}

int main()
{
	int fd;
	fd = 1;
	char *line;
	write(fd,"abcdefgh\n",9);
	write(fd,"ikjlmnop\n",9);
	write(fd,"qrstuvwx\n",9);
	write(fd,"yzabcdda\n",9);
	write(fd,"qwerty12\n",9);
	close(fd);
	get_next_line(fd,&line);
	printf("%s",line);
}

































