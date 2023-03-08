#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>

int main(int argc, char *argv[]){
    if(argc == 3){
        printf("Hard link created\n");
        return link(argv[1], argv[2]);
    }
    else if(argc == 4){
        if(strcmp(argv[1], "-s") == 0){
            printf("Symbolic link created\n");
            return symlink(argv[2], argv[3]);
        }
        else
            printf("Option must be -s for symbolic link\n");
    }
    else{
        printf("Invalid number of arguments\n");
    }
    return 0;
}