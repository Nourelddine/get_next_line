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

int find_char(const char *s, char c)
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

/*int        find_char(char *s, char c)
{
    int     i;

    i = 0;
    if (s == NULL)
        return (0);
    while (s[i])
    {
        if (s[i] == c)
            return (i);
		i++;
    }
    return (0);
}*/

int get_next_line(const int fd, char **line)
{
	int sz;
	char buffer[BUFF_SIZE + 1];
	static t_list *file;
	t_list *tmp;
	int i;

	if ((read(fd, buffer, 0) < 0 || fd < 0 || !line))
	{
		return (-1);
	}
	tmp = (t_list *)ft_memalloc(sizeof(t_list));
	tmp->content = ft_strnew(0);
	ft_lstinsert(&file, tmp);
	while ((sz = read(fd, buffer, BUFF_SIZE)) && sz)
	{
		buffer[sz] = '\0';
		if (!(file->content = ft_strjoin(file->content, buffer)))
		{
			return (-1);
		}
		if ((ft_strchr(buffer, '\n')))
		{
			break;
		}
	}
	if (sz == 0 && !ft_strlen((char *)file->content))
		return (0);
	i = find_char(file->content, '\n');
	*line = ft_strsub(file->content, 0, i);
	file->content = ft_strchr(file->content, '\n') + 1;
	return (1);
}

// int main()
// {
// 	int fd;
// 	char *line;
// 	fd = open("cmp.txt",O_RDONLY);
// 	while (get_next_line(fd,&line))
// 	{
// 		printf("%s",line);
// 		free(line);
// 	}
// }