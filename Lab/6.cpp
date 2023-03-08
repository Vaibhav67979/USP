#include<stdio.h>
#include<unistd.h>
#include<iostream>
using namespace std;

static void show(char *s) {
    setbuf(stdout , NULL);
    for(char *c=s;*c != '\0';c++) {
        putc(*c , stdout);    
    }
}

int main() {
    for(int i=0;i < 5;i++) {
        pid_t pid = fork();
        
        if(pid < 0) {
            cout<<"Failed to execute fork"<<endl;    
        }
        else if(pid == 0) {
            show("This is child process\n");
        }
        else {
            show("This is parent process\n");        
        }
    }    

    return 0;
}
