/*
 *============================================================================
Name : 17b.c
Author : Ayush Kumar
Description :. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file. 
Date: 7th sept, 2025
============================================================================
 * */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    struct flock lock;
    int fd;
    int ticket_number;
    
    fd = open("ticket.txt", O_RDWR);
    
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; // Lock the entire file
    
    printf("Attempting to get a write lock on the ticket file...\n");
   
    fcntl(fd, F_SETLKW, &lock);
    
    printf("Lock acquired! Reading ticket number.\n");
    
    read(fd, &ticket_number, sizeof(int));
    
    printf("Current ticket number is: %d\n", ticket_number);
    ticket_number++;
    
    lseek(fd, 0, SEEK_SET);
   
    write(fd, &ticket_number, sizeof(int));
    
    printf("New ticket number is: %d. Releasing lock.\n", ticket_number);
    
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    
    close(fd);
    
    return 0;
}

