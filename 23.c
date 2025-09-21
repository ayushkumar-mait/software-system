/*
============================================================================
Name : q23.c
Author : Ayush Kumar
Description : Write a program to create a Zombie state of the running program
Date: 7th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
       
        return 1;
    } else if (pid == 0) {
        
        printf("Child process is exiting. My PID is %d\n", getpid());
        exit(0);
    } else {
      
        printf("Parent process started. My PID is %d\n", getpid());
        printf("The child process (PID: %d) has exited and is now a zombie.\n", pid);
        printf("Sleeping for 20 seconds. Do not kill the parent process!\n");
        printf("Check the process list in another terminal (ps aux | grep Z).\n");
        sleep(20);
        printf("Parent is now exiting, which will clean up the zombie process.\n");
    }

    return 0;
}
/*OUTPUT:
 *./a.out
Enter File Name
: Success
 *root@ubuntu-dev:/ss_handson# ps aux | grep create_zombie
root       535  0.0  0.0   3124  1640 pts/2    S+   17:16   0:00 grep --color=auto create_zombie
 * */
