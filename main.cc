
//Name: Andrew Brainerd
//This is the same code I submitted the first time I took this course
		   



#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
								
	pid_t childP, ParentP; 
	int status;
	ParentP = getpid();
	
	childP = fork();
	if(childP == -1){ //child process failed
		printf("\nFork failed");
		perror("fork");
		exit(EXIT_FAILURE);
	}
	
	else if(childP == 0){
		childP = getpid();

		printf("\nChild PID: %d\n", childP);
		printf("\nParent PID: %d\n", ParentP);
		printf("\nCall successful... ");
		execl("./counter","counter","5",'\0');
	}
	else{
		ParentP = waitpid(childP, &status, WNOHANG);
		if(ParentP == -1){
			printf("\nWait failed");
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
	
	return 0;
	
	
}
