#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L

#include <sys/types.h>
#include <sys/wait.h>
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <iostream>
#include <unistd.h>

#ifdef SOLARIS
#define PSCMD "ps -a -o pid,ppid,s,tty,comm"
#else
#define PSCMD "ps -o pid,ppid,state,tty,command"
#endif

using namespace std;

int main() {
	// Fork
	pid_t pid = fork();
	if (pid < 0) // Error while forking
		perror("fork");
	else if (pid == 0) // Child
		_exit(0);

	// Parent
	sleep(4);

	// Execute the `PSCMD` command
	system(PSCMD);

	_exit(0);

	return 0;
}
