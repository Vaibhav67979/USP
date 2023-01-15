#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
using namespace std;

int main()
{

	key_t key = ftok("/Desktop/shm.txt",100);

	int shmid = shmget(key,1024,0666|IPC_CREAT);

	char *str = (char*) shmat(shmid,(void*)0,0);
	

	cout<<"Write Data : ";

	scanf("%[^\n]s", str);
	
	printf("Data read from memory: %s\n",str);
	
	shmdt(str);

	return 0;

}
