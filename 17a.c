/*
 *============================================================================
Name : 17a.c
Author : Ayush Kumar
Description :. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file. 
Date: 7th sept, 2025
============================================================================
 * */
 #include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    int ticket_number = 1;

    fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    write(fd, &ticket_number, sizeof(int));
    
    close(fd);
    
    printf("Initial ticket number written to ticket.txt.\n");

    return 0;
}
/*OUTPUT:
 *root@ubuntu-dev:/ss_handson# ./ticket_set
Initial ticket number written to ticket.txt.
root@ubuntu-dev:/ss_handson# ./ticket_reserve
Attempting to get a write lock on the ticket file...
Lock acquired! Reading ticket number.
Current ticket number is: 1
New ticket number is: 2. Releasing lock.
 *
 * */
