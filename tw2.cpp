#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<iostream>
#include<unistd.h>
using namespace std;

int main(){
	#ifdef _POSIX_JOB_CONTROL
		cout << "BSD style job control is supported\n";
	#else
		cout << "System doesn't support job control\n";
	#endif
	
	#ifdef _POSIX_SAVED_IDS
		cout << "System supports saved set-UID and set-GID\n";
	#else
		cout << "System doesn't support saved set-UID and set-GID\n";
	#endif
	
	#ifdef _POSIX_CHOWN_RESTRICTED
		cout << "chown restricted option is : " << _POSIX_CHOWN_RESTRICTED << endl;
	#else
		cout << "System doesn't support chown restricted option\n";
	#endif
	
	#ifdef _POSIX_NO_TRUNC
		cout << "Pathname truncation option is : " << _POSIX_NO_TRUNC << endl;
	#else
		cout << "System doesn't support Pathname truncation\n";
	#endif
	
	#ifdef _POSIX_VDISABLE
		cout << "Disabling character is : " << _POSIX_VDISABLE << endl;
	#else
		cout << "System doesn't support Disabling character\n";
	#endif
	return 0;
}
