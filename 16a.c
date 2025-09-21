/*
 *============================================================================
Name : Q16a.c
Author : Ayush Kumar
Description :Write a program to perform mandatory locking.
a. Implement write lock 
Date: 7th sept, 2025
============================================================================
 * */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    struct flock lock;
    int fd;
    const char *filename = "lock_file.txt";

    fd = open(filename, O_WRONLY | O_CREAT, 0666);

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf("Attempting to get a write lock on the file...\n");

    // Acquire the lock
    fcntl(fd, F_SETLKW, &lock);

    printf("Lock acquired! The file is now write-locked.\n");
    printf("You can now try to open this file from another terminal.\n");
    printf("Press Enter to release the lock and exit.\n");

    getchar();


    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);

    printf("Lock released. Exiting program.\n");

    close(fd);

    return 0;
}
/*
 * OUTPUT:
 *root@ubuntu-dev:/ss_handson# cc 16a.c
root@ubuntu-dev:/ss_handson# ./a.out
Attempting to get a write lock on the file...
Lock acquired! The file is now write-locked.
You can now try to open this file from another terminal.
Press Enter to release the lock and exit.

Lock released. Exiting program.
 * */

