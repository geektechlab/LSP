#include <stdlib.h>
#include <unistd.h>

int main(){

	/* solution */
  //ensure the environment only has the path we want
  //and overwrite
  setenv("PATH","/bin",1);

  char * args[] = {"cat",NULL};

  execvp(args[0],args);

}
