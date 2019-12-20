#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
	if (!argv[1]) {
		exit(0);
	}
	char komento[50];
	system(strcpy(komento, "cat test"));
	execvp(argv[1], argv+1);
	printf("ei tulostu\n");
	return(0);
}
