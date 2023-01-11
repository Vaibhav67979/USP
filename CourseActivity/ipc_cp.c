#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2];
    pid_t cpid;

    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {
        // child process - the coprocess
        close(pipe_fd[1]);    // close the write end of the pipe
        dup2(pipe_fd[0], 0);  // redirect standard input to the read end of the pipe
        execlp("ls", "ls", "-l", "-a", "-h", (char *) NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        // parent process - the primary process
        close(pipe_fd[0]);    // close the read end of the pipe
        dup2(pipe_fd[1], 1);  // redirect standard output to the write end of the pipe
        fprintf(stdout, "Command to coprocess\n");
        fflush(stdout);
        close(pipe_fd[1]);    // close the write end of the pipe
    }

    return 0;
}

