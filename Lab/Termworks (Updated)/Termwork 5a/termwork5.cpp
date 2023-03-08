#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv, char **envp) {
	cout << "\n\n Using environment variables passed to command line arguments \n\n Environment variable = Value format \n\n";
	for (int i = 0; envp[i] != (char *) 0; i++)
		cout << envp[i] << '\n';

	cout << "\n\n Using getenv, stdlib.h\n\n";

	char *env = getenv("HOME");
	cout << "PATH = " << env << '\n';

	char envVar[10][10] = {"SHELL", "TERM", "USER", "PATH"};
	for (int i = 0; i < 4; i++)
		cout << envVar[i] << " = " << getenv(envVar[i]) << '\n';

	cout << "\n\n Using external variable environ \n\n";
	extern char **environ;
	for (int i = 0; environ[i] != (char *) 0; i++)
		cout << environ[i] << '\n';

	return 0;
}
