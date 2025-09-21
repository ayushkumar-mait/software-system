/*
 *============================================================================
Name : Q14a.c
Author : Ayush Kumar
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 7th sept, 2025
============================================================================
 * */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat file_info;

    stat(argv[1], &file_info);

    printf("File Type: ");

    if (S_ISREG(file_info.st_mode)) {
        printf("Regular File\n");
    } else if (S_ISDIR(file_info.st_mode)) {
        printf("Directory\n");
    } else if (S_ISLNK(file_info.st_mode)) {
        printf("Symbolic Link\n");
    } else if (S_ISCHR(file_info.st_mode)) {
        printf("Character Device\n");
    } else if (S_ISBLK(file_info.st_mode)) {
        printf("Block Device\n");
    } else if (S_ISFIFO(file_info.st_mode)) {
        printf("FIFO (Named Pipe)\n");
    } else if (S_ISSOCK(file_info.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown\n");
    }

    return 0;
}
/*OUTPUT:
 *root@ubuntu-dev:/ss_handson# vim 14a.c
root@ubuntu-dev:/ss_handson# gcc -o file_type 14a.c      
root@ubuntu-dev:/ss_handson# ./file_type 14a.c      
File Type: Regular File
root@ubuntu-dev:/ss_handson# ln -s 14a.c link_to_file
root@ubuntu-dev:/ss_handson# ./file_type link_to_file
File Type: Regular File
root@ubuntu-dev:/ss_handson# 

 *
 * */

