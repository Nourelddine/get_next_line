#include "./get_next_line.h"

int main()
{
	char buffer[BUFF_SIZE];
	int fd = open("test.opt",O_RDONLY);
	int red = read(fd,buffer,BUFF_SIZE);
	buffer[red] = '\n';
	printf("%s",buffer);
}
