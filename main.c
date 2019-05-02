#include "./get_next_line.h"

int main()
{
	int fd;
	char *line;
	fd = open("test.opt", O_RDONLY);
	int res;
	while ((res = get_next_line(fd, &line)) > 0)
	{
		printf("[%d]\n", res);
		printf("[%s]\n", line);
		ft_strdel(&line);
	}
	printf("[%d]\n", res);
	printf("[%s]\n", line);
	ft_strdel(&line);
	return (0);
}