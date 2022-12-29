#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define PERMS 0666
char fname[256];

int main(){
	ssize_t n;
	char buff[512];
	int readfd, writefd,fd;
	if(mkfifo(FIFO1, PERMS) < 0)
		printf("can't read fifo files...\n");
	if(mkfifo(FIFO2, PERMS) < 0)
		printf("can't read fifo files...\n");
	printf("Waiting for connection from the client...\n");
	readfd = open(FIFO1, O_RDONLY, 0);
	writefd = open(FIFO2, O_WRONLY, 0);
	printf("Connection established...\n");
	read(readfd, fname, 255);
	printf("Client has requested file %s\n", fname);
	if((fd = open(fname, O_RDWR)) <  0){
		strcpy(buff, "file does not exist!");
		write(writefd, buff, strlen(buff));
	}
	else{
		while((n = read(fd, buff, 512)) > 0)
			write(writefd, buff, n);
	}
	close(readfd); unlink(FIFO1);
	close(writefd); unlink(FIFO2);
}
