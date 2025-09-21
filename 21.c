/*
============================================================================
Name : q21.c
Author : Ayush Kumar
Description :  Write a program, call fork and print the parent and child process id.
Date: 7th Sep, 2025.
============================================================================
*/

#include <sys/types.h> // Import for `fork` & `getpid` system call
#include <unistd.h>    // Import for `fork` & `getpid` system call
#include <stdio.h>     // Import for printf function

int main(){
	if(!fork()){
		printf("Child PID: %d\n",getpid());
		printf("Parent PID: %d\n",getppid());
	}
	return 0;
}

/*
 * OUTPUT:
 *./a.out
Child PID: 521
Parent PID: 1

 *
*/

