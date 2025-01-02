#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{	
	pid_t pid;
	int fd = open("hello.txt", O_RDWR);
	char *address;
	if (fd < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	struct stat sbuff;
	fstat(fd, &sbuff);
	int fsize = sbuff.st_size;


	address = mmap(NULL, fsize, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
	if (address == MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if (pid == 0) //child
	{
		printf("Child Data:%s\n", address);
		munmap(address, fsize);;
		_exit(0);
	} else if (pid > 0) {
		wait(NULL);
		printf("Parent Data:%s\n", address);
		munmap(address, fsize);;
	}
	close(fd);

	return 0;
}	