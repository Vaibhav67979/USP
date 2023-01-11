#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<iostream>
#include<unistd.h>
#include<limits.h>
using namespace std;

int main(){
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
		
	if ((res = fpathconf(0, _PC_LINK_MAX)) == -1)
		perror("fpathconf");
	else
		cout << "Max number of links a file may have : " << res << endl;
		
	if ((res = fpathconf(0, _PC_CHOWN_RESTRICTED)) == -1)
		perror("fpathconf");
	else
		cout << "_POSIX_CHOWN_RESTRICTED value : " << res << endl;
		
	return 0;
}
