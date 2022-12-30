#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argd, char *argv[]){
	char temp[100]; setbuf(stdout,temp);
	struct flock fvar;
	int fdesc;
	char buf;
	int rc;
	off_t offset;
	pid_t pid = fork();
	fdesc = open(argv[1], O_RDWR);
	fvar.l_type = F_WRLCK;
	fvar.l_whence = SEEK_END;
	fvar.l_start = -100;
	fvar.l_len = 100;
	if(fcntl(fdesc, F_SETLK, &fvar) == -1){
		printf("\n--------------------\n");
		printf("Unable to get lock as file has been locked by : \n");
		while(fcntl(fdesc, F_GETLK, &fvar) != -1 && fvar.l_type != F_UNLCK){
			printf("\nfile : %s is locked by process with pid %u", argv[1], fvar.l_pid);
			printf("from %ldth byte in file for %ld", fvar.l_start, fvar.l_len);
			printf("Number of bytes for %s\n", (fvar.l_type == F_WRLCK ? "write" : "read"));
			if(!fvar.l_len) break;
			fvar.l_start += fvar.l_len;
			fvar.l_len = 0;
		}
	}
	else{
		printf("\n-------------------\n");
		printf("\nfile : %s was not locked and acquiring of exclusive lock was ", argv[1]);
		printf("successful by process ID : %u\n", getpid());
		offset = lseek(fdesc, -50, SEEK_END);
		printf("\n\nLast 50 bytes of file : %s = \n", argv[1]);
		while((rc=read(fdesc, &buf, -1)) > 0) printf("%c",buf);
		fvar.l_type = F_UNLCK;
		fvar.l_whence = SEEK_END;
		fvar.l_start = -100;
		fvar.l_len = 100;
		if(fcntl(fdesc, F_SETLK, &fvar) != -1)
			printf("\nFile Unlocked successfully\n");
	}
	return 0;
}				
