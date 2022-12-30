#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<iostream>
#include<unistd.h>
#include<limits.h>
#include<stdio.h>
using namespace std;

void runtime(){
	int res;
	if ((res = sysconf(_SC_CHILD_MAX)) == -1)
		perror("sysconf");
	else
		cout << "Max number of child processes : " << res << endl;
		
	if ((res = sysconf(_SC_OPEN_MAX)) == -1)
		perror("sysconf");
	else
		cout << "Max number of files that can be open at a time : " << res << endl;
		
	if ((res = sysconf(_SC_CLK_TCK)) == -1)
		perror("sysconf");
	else
		cout << "Max number of clock ticks per second : " << res << endl;
		
	if ((res = pathconf("/", _PC_PATH_MAX)) == -1)
		perror("pathconf");
	else
		cout << "Max number of bytes in path name : " << res << endl;
		
	if ((res = pathconf("/", _PC_NAME_MAX)) == -1)
		perror("pathconf");
	else
		cout << "Max number of bytes in file name : " << res << endl;
}

void compiletime(){
	#ifdef _POSIX_CHILD_MAX
		cout << "Max number of child processes : " << _POSIX_CHILD_MAX << endl;
	#else 
		cout << "_POSIX_CHILD_MAX not suppported\n";
	#endif
	
	#ifdef _POSIX_PATH_MAX
		cout << "Max number of bytes in path name : " << _POSIX_PATH_MAX << endl;
	#else 
		cout << "_POSIX_PATH_MAX not suppported\n";
	#endif
	
	#ifdef _POSIX_NAME_MAX
		cout << "Max number of bytes in file name : " << _POSIX_NAME_MAX << endl;
	#else 
		cout << "_POSIX_NAME_MAX not suppported\n";
	#endif
	
	#ifdef _POSIX_OPEN_MAX
		cout << "Max number of files that can be open at a time : " << _POSIX_OPEN_MAX << endl;
	#else 
		cout << "_POSIX_OPEN_MAX not suppported\n";
	#endif
}

int main(){
	int opt;
	while(1){
		cout << "1. Runtime limits\n2. Compile limits\n3. Exit\n";
		cout << "Enter option : ";
		cin >> opt;
		
		switch(opt){
			case 1 : runtime(); break;
			case 2 : compiletime(); break;
			case 3 : exit(0);
			default : cout << "Invalid choice\n";
		}
	}
}
