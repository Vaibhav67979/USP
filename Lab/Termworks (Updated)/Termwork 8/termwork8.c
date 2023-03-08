#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t child_pid = fork();

	if (child_pid < 0) {
		// Error while forking
		perror("fork");
		return 1;
	} else if (child_pid == 0) {
		// Child

		pid_t child2_pid = fork();

		if (child2_pid < 0) {
			perror("fork");
			exit(1);
		} else if (child2_pid == 0) {
			// Child2
	
			sleep(1);
			printf("2nd Child's PPID: %zd\n\n", getppid());
		}
	} else {
		// Parent

		wait(NULL);
		sleep(2);
		system("ps -o pid,ppid,state,tty,command");
	}

	return 0;
}
