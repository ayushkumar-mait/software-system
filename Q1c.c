/*
============================================================================
Name : Q1_c.c
Author : Ayush Kumar
Description : Create a FIFO file using the `mkfifo` library function or `mknod` system call
Date: 7th Sep, 2025.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    // mkfifo(pathname, mode)
    // 0666 gives read/write permissions to owner, group, and others
    if (mkfifo("my_fifo_from_c", 0666) == -1) {
        perror("mkfifo failed");
        return 1;
    }
    printf("FIFO created successfully.\n");
    return 0;
} 
/*
FIFO created successfully.
*/
