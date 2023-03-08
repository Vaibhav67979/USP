#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	// Check if file name is passed as command line argument

	char temp[1024];
	// As fork is used - to get separate outputs, set stdout as buffered, setbuf(stdout, temp);
	setbuf(stdout, temp);

	struct flock fvar; // flock structure variable
	int fdesc; // file descriptor
	char buf; // buffer for reading contents from file
	int rc; // variable for count of bytes read by read API

	off_t offset;

	pid_t pid = fork();

	fdesc = open(argv[1], O_RDWR);

	fvar.l_type = F_WRLCK;
	fvar.l_whence = SEEK_END;
	fvar.l_start = -100;
	fvar.l_len = 100;

	if (fcntl(fdesc, F_SETLK, &fvar) == -1) {
		// Check whether the region is locked
		// fcntl unsuccessful, region is locked, print pid of the process which acquired locked
		printf("\n-----------------------------\n");
		printf("Unable to get lock as file has been locked by: \n");
		while (fcntl(fdesc, F_GETLK, &fvar) != -1 && fvar.l_type != F_UNLCK) {
			printf("\nFile: %s is locked by process with pid: %u", argv[1], fvar.l_pid);
			printf("from %ldth byte in file for %ld", fvar.l_start, fvar.l_len);
			printf("number of bytes, for %s\n\n", (fvar.l_type == F_WRLCK ? "write" : "read"));

			if (!fvar.l_len) break;

			fvar.l_start += fvar.l_len;
			fvar.l_len = 0;
		}
	} else {
		// fcntl successful, as region was not locked hence process was able to get write lock
		printf("\n-----------------------------\n");
		printf("\n\n File: %s was not locked and acquiring of Exclusive Lock was", argv[1]);
		printf(" successful by process Id: %u\n", getpid());

		offset = lseek(fdesc, -50, SEEK_END); // Point to last 50th byte, print error if lseek fails

		printf("\n\n Last 50 bytes of file: %s = \n", argv[1]);

		while ((rc = read(fdesc, &buf, 1)) > 0)
			printf("%c", buf); // Read the last 50 bytes

		fvar.l_type = F_UNLCK; // unlocks a specific region
		fvar.l_whence = SEEK_END;
		fvar.l_start = -100;
		fvar.l_len = 100;

		if (fcntl(fdesc, F_SETLKW, &fvar) == -1) {
			// Log errors
			perror("fcntl");
			exit(1);
		}
		
		printf("\n File unlocked successfully\n\n");
	}

	return 0;

}
