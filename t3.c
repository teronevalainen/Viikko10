 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <sys/wait.h>
 #include <sys/types.h>
 int main(int argc, char **argv) {
     if (!argv[1]) {
     	exit(1);
     } 
     int pid, status;
  	
     switch (pid = fork()) {
     case -1:
		exit(1);			/* error in fork */
            
     case 0:               /* child process */
         printf("Child %d was born, running child...\n", pid);
         if (execvp(argv[1], argv+1) == -1) {
            perror("execvp");
            exit(1);
         }
        break;
     default:              /* parent process */
        printf("Child %d was born, waiting in parent...\n", pid);
        if (wait(&status) == -1) {
           perror("wait");
           exit(1);
        }
       printf("Child done, status: %d\n", status);
       break;
    }
}
