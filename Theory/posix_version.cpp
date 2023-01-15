#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<iostream>
using namespace std;

int main(){
	#ifdef _POSIX_VERSION
		cout << "System conforms to POSIX" << _POSIX_VERSION << endl;
	#else
		cout << "System doesn't conform to POSIX\n";
	#endif
	return 0;
}
