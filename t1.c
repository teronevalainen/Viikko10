#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/file.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
  int fd = open(argv[1], O_WRONLY);
  time_t t;
  if(fd == -1) {
    printf("Unable to open the file\n");
    exit(1);
  }    
	time(&t);
	printf("pid: %3d, getting write exclusive lock at %s\n", getpid(), ctime(&t));
	flock(fd, LOCK_EX);
	time(&t);
	printf("pid: %4d, exclusive locked at %s\n", getpid(), ctime(&t));
	sleep(20);
	flock(fd, LOCK_UN);
	time(&t);
	printf("pid: %4d, unlocked at %s\n", getpid(), ctime(&t)); 
	
	if (fd =open(argv[1], O_RDONLY) == -1) {
		printf("Unable to open the file\n");
		exit(1);
	}
	time(&t);
	printf("pid: %3d, getting read shared lock at %s\n", getpid(), ctime(&t));
	flock(fd, LOCK_SH);
	time(&t);
	sleep(20);
	flock(fd, LOCK_UN);
	time(&t);
	printf("pid: %4d, unlocked at %s\n", getpid(), ctime(&t)); 
	
}


