#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    int shmid;
    char *shmptr;
    char message[] = "Hello, World!";

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, sizeof(message), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process's address space
    shmptr = (char *) shmat(shmid, NULL, 0);
    if (shmptr == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    if (fork() == 0) {
        // Child process
        printf("Child: Reading message from shared memory: ");
        puts(shmptr);
    } else {
        // Parent process
        printf("Parent: Writing message to shared memory: %s\n", message);
        strcpy(shmptr, message);
    }

    // Detach shared memory segment
    shmdt(shmptr);

    // Remove shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

