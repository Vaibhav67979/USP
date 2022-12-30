#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<ctype.h>

static void charatatime();

int main(){
	pid_t pid;
	pid = fork();
	if(pid < 0)
		printf("fork error");
	else if(pid == 0)
		charatatime("Output of child\n");
	else
		charatatime("Output of parent\n");
}

static void charatatime(char *str){
	char *ptr;
	int c;
	setbuf(stdout, NULL);
	for(ptr = str; (c = *ptr++) != 0;)
	putc(c,stdout);
}
