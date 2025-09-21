/*
============================================================================
Name : q26.c
Author : Ayush Kumar
description: Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 7th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main()
{
    char* arguments[] = {"cat", "file1.txt", NULL};
    execv("../../bin/cat", arguments);
    perror("execv failed");
    return 1; // Return 1 to indicate an error
}
/*
root@ubuntu-dev:/ss_handson# echo "Ayush the gai guy!" > file1.txt
root@ubuntu-dev:/ss_handson# ./a.out
Ayush the gai guy!

  */

