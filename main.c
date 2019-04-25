#include "./get_next_line.h"

int main()
{
	int fd;
	fd = 1;
	write(fd,"aaa\nbbb\nccc\n",16);
	char *line;
	get_next_line(fd,&line);
	printf("%s \n",line);
}
