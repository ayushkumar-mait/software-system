/*
============================================================================
Name : q24.c
Author : Ayush Kumar
Description : Write a program to create an orphan process
Date: 7th Sep, 2025.
============================================================================
*/

#include <sys/types.h> // Import for `fork` system call
#include <unistd.h>    // Import for `fork` system call
#include <stdio.h>     // Import for `printf` function

int main(){
	if(fork()){
		printf("Parent PID: %d\n", getpid());
        printf("Parent shifting to 4sec sleep\n");
        sleep(4);
		printf("Parent wakes up\n");
        printf("Exiting parent!\n");
		_exit(0);
	}else{
		printf("Child PID: %d\n", getpid());
        printf("Child shifting to 10sec sleep\n");
        sleep(10);
        printf("Child awake\n");
	}
	return 0;
}
/*OUTPUT:
 * ./a.out
Parent PID: 546
Parent shifting to 4sec sleep
Child PID: 547
Child shifting to 10sec sleep

Parent wakes up
Exiting parent!
root@ubuntu-dev:/ss_handson#
root@ubuntu-dev:/ss_handson# Child awake
 *
 * */
