#include "./get_next_line.h"

void	handle_file(const int fd, t_list **list)
{
	int sz;
	char buffer[BUFFER_SIZE + 1];
	t_list *tmp;
	t_list *save;

	while ((sz = read(fd,buffer,BUFFER_SIZE)) && sz)
	{
		buffer[sz] = '\0';
		tmp = (t_list*)malloc(sizeof(t_list));
		tmp->content = ft_strdup(buffer);
		tmp->content_size = sz;
		ft_lstinsert(&(*list),tmp);
	}
}

int		file_size(t_list *list)
{
	int	size;
	size = 0;
	while (list)
	{
		size+= list->content_size;
		list = list->next;
	}
	return (size);
}
int count()
{
	static int l = -1;
	l++;
	return (l);
}
int		get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list	*p;
	char	*str;
	char **words;
	static int l = 0;
	handle_file(fd,&file);
	str = ft_strnew(file_size(file));
	p = file;
	while (p)
	{
		ft_strcat(str,p->content);
		p = p->next;
	}
	words = ft_strsplit(str,'\n');
	free(str);
	*line = ft_strdup(words[l++]);
	return (1);
}
