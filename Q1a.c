/*
============================================================================
Name : Q1_a
Author : Ayush Kumar
Description :Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 7th Sep, 2025.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>

int main() {
	if (symlink("original.txt", "soft_link_symlink.txt")==-1) {
		printf("symlink failed\n");
		return -1;
	}
	printf("Success\n");
	return 0;
}
/*OUTPUT:
 *./a.out
Success

 *
 * */
