#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

int main(int argc, char *argv[]){
    struct flock lock;
    char buf[100];
    if(argc == 1){
        printf("Usage = %s <filename>\n", argv[0]);
        return -1;
    }
    int fd = open(argv[1], O_RDWR);
    if(fd == -1){
        printf("File opening error\n");
        exit(0);
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_END;
    lock.l_start = SEEK_END-100;
    lock.l_len = 100;

    printf("Press enter to lock\n");
    getchar();

    if((fcntl(fd, F_SETLK, &lock)) == -1){
        fcntl(fd, F_GETLK, &lock);
        printf("File already locked by process : %d\n", lock.l_pid);
        return -1;
    }
    printf("File locked\n");

    off_t n = lseek(fd, SEEK_END-50, SEEK_END);
    read(fd, buf, 100);
    printf("Data : %s\n", buf);
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_CUR;
    lock.l_start = 0;
    lock.l_len = 0;
    if((fcntl(fd, F_UNLCK, &lock)) == -1)
        printf("Unlock error\n");
    printf("Unlocked\n");
    return 0;
}
