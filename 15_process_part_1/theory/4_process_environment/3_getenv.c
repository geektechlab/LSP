#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]){
	int i;
	char *env;
	printf(" No of arguments = %d\n",argc);
	for(i=0;i<argc;i++)
		printf("%d    %s\n",i,argv[i]);
	env = getenv("HOME");
	printf(" HOME = %s\n",env);
	/* run [ man getenv ] */
	env = getenv("env1");
	printf(" env1 = %s\n",env);
	getchar();
}
