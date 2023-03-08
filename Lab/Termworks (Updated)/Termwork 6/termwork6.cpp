#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L

#include <iostream>
#include <cstdio>
#include <unistd.h>

using namespace std;

static void char_at_a_time(char *);

int main() {
	for (int i = 0; i < 5; i++) {
		// Fork
		pid_t pid = fork();

		if (pid < 0) {
			// Error while forking
			perror("fork");
			return -1;
		} else if (pid == 0)
			// Child
			char_at_a_time("Output from child\n");
		else
			// Parent
			char_at_a_time("Output from parent\n");
	}

	return 0;
}

static void char_at_a_time(char *str) {
	setbuf(stdout, NULL);

	char *ptr;
	int c;
	for (ptr = str; (c = *ptr++) != 0;)
		putc(c, stdout);
}

