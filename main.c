#include "./get_next_line.h"


int main()
{
	int fd;
	int fd1;
	char *line;
	fd = open("test.opt",O_RDONLY);
	fd1 = open("test.opt1",O_RDONLY);
	get_next_line(fd,&line);
	printf("%s\n",line);
	free(line);
	get_next_line(fd,&line);
	printf("%s\n",line);
	free(line);
	/****************/
	get_next_line(fd1,&line);
	printf("%s\n",line);
	free(line);
	get_next_line(fd1,&line);
	printf("%s\n",line);
	free(line);
}