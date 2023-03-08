#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void sys(const char *cmd_str) {
	pid_t pid = fork();

	if (pid == 0)
		// Child
		execl("/bin/bash", "bash", "-c", cmd_str, NULL);
	else
		waitpid(pid, NULL, 0);
}

int main(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		sys(argv[i]);
		printf("\n");
	}

	_exit(0);

	return 0;
}
