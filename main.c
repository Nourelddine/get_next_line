#include "./get_next_line.h"

int main()
{
	char buffer[BUFFER_SIZE];
	int fd = open("test.opt",O_RDONLY);
	int red = read(fd,buffer,BUFFER_SIZE);
	buffer[red] = '\n';
	printf("%s",buffer);
}
