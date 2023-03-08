#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<iostream>
using namespace std;

int main(int argc , char *argv[]) {
    char buf[512];
    int fd = open(argv[1] , O_RDWR);
    pid_t pid = fork();

    struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_END;
    fl.l_start = -100;
    fl.l_len = 100;

    if(fcntl(fd , F_SETLK , &fl) == -1) {
        cout<<"\nUnable to lock , it has already locked"<<endl;
        
        while(fcntl(fd , F_GETLK , &fl) != -1 && fl.l_type != F_UNLCK) {
            cout<<"The file is locked by process pid : "<<fl.l_pid;
            cout<<" from "<<fl.l_start<<" for "<<fl.l_len<<" bytes";
            cout<<" for "<<(fl.l_type == F_WRLCK ? "write" : "read")<<"."<<endl;
            
            if(fl.l_len == 0) break;

            fl.l_start += fl.l_len;
        }
    }
    else {
        cout<<"\nThe file region is not locked"<<endl;
        cout<<"Now region is locked by process pid : "<<getpid()<<endl;
        cout<<"\nThe last 50 bytes of file under locked region\n"<<endl;
        
        off_t off_set = lseek(fd , -50 , SEEK_END);

        ssize_t size = read(fd , buf , 50);
        buf[size] = '\0';
        cout<<buf<<endl;
    
        fl.l_type = F_UNLCK;
        fl.l_whence = SEEK_END;
        fl.l_start = -100;
        fl.l_len = 100;

        if(fcntl(fd , F_SETLKW , &fl) != -1)
            cout<<"File is unlocked"<<endl;        
    }

    return 0;
}