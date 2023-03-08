#define _POSIX_SOURCE
#define _POSIC_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<ctype.h>

#ifdef SOLARIS
#define PSCMD "ps -a -o pid,ppid,s,tty,comm"
#else
#define PSCMD "ps -o pid,ppid,state,tty,command"
#endif

int main(){
	pid_t pid;
	pid =  fork();
	if( pid < 0)
		perror("fork error");
	else if(pid == 0)
		exit(0);
	sleep(4);
	system(PSCMD);
	exit(0); 
}
