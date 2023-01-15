#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<iostream>
#include<unistd.h>
#include<limits.h>
using namespace std;

int main(){
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
	
	#ifdef _POSIX_PIPE_BUF
		cout << "Max number of bytes in pipe file : " << _POSIX_PIPE_BUF << endl;
	#else 
		cout << "_POSIX_PIPE_BUF not suppported\n";
	#endif
	
	#ifdef _POSIX_LINK_MAX
		cout << "Max number of links a file may have : " << _POSIX_LINK_MAX << endl;
	#else 
		cout << "_POSIX_LINK_MAX not suppported\n";
	#endif
}
