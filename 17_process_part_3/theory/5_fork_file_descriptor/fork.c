#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

/* it will print hell, not hehe */

#define CHILD 0

main(){
	int fd;
	char buf[2];
	pid_t pid;	
	int childstatus;
	fd = open("./test",O_RDONLY);
	pid = fork();
	if( pid == CHILD){
		read(fd,buf,2);
		printf(" in child %c\n",buf[0]);
		printf(" in child %c\n",buf[1]);
		close(fd);
	}
	// parent
	else{
		wait(&childstatus);
		read(fd,buf,2);
		printf(" in parent %c\n",buf[0]);
		printf(" in parent %c\n",buf[1]);
		close(fd);
	}
}
