#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
	int parameter = (long)argv[1];
	int i;
	pid_t currentPID = getpid();
	
	for(i = 1; i < 6; i++){
		printf("\nProcess: %d", currentPID);
		printf(" %d", i, "\n\n");
	}
	printf("\nProcess: %d", currentPID, " exit ");
	return parameter;
}
