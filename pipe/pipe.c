#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	//0 read, 1 write
	int a[2];

	char buff[64];

	if(pipe(a) == -1)
	{
		perror("pipe");
		exit(1);
	}

	//write
	write(a[1], "code", 5);
	printf("\n");


	//read
	read(a[0], buff, 5);
	printf("%s\n", buff);

	//write
	write(a[1], "style", 5);
	printf("\n");

	//read
	read(a[0], buff, 5);
	printf("%s\n", buff);


	return 0;
}
