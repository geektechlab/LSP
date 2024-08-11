#include <stdio.h>
#include <fcntl.h>

int main()
{
	/* second argument tells mode for file opening, creates hello.txt */
	int fd = creat("hello.txt", 0660);

	if (fd < 0)
		perror("failed to create file");
	else
		printf("File created successfully\n");

	close(fd);
	return 0;
}
