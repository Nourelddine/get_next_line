#include "./get_next_line.h"


int main()
{
	int fd;
	char *line;
	fd = open("test.opt",O_RDONLY);
	while (get_next_line(fd,&line) == 1)
	{
		printf("%s\n",line);
		free(line);
	}
}