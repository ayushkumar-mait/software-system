/*
 *============================================================================
Name : Q16b.c
Author : Ayush Kumar
Description :Write a program to perform mandatory locking.
b. Implement read lock 
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
    const char *filename = "read_file.txt";

    fd = open(filename, O_RDONLY | O_CREAT, 0666);

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf("Attempting to get a read lock on the file...\n");

    fcntl(fd, F_SETLKW, &lock);

    printf("Read lock acquired! The file is now read-locked.\n");
    printf("You can now try to open this file from another terminal.\n");
    printf("Press Enter to release the lock and exit.\n");

    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);

    printf("Lock released. Exiting program.\n");

    close(fd);

    return 0;
}
/*OUTPUt:
 *root@ubuntu-dev:/ss_handson# gcc 16b.c
root@ubuntu-dev:/ss_handson# ./a.out
Attempting to get a read lock on the file...
Read lock acquired! The file is now read-locked.
You can now try to open this file from another terminal.
Press Enter to release the lock and exit.

Lock released. Exiting program.
 *
 * */
