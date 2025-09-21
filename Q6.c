
/*
 *============================================================================
Name : Q6.c
Author : Ayush Kumar
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 28th Aug, 2025
============================================================================
 * */


#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char buffer[1024];
    ssize_t bytes_read;

    //  (Ctrl+D)
    while ((bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
    {
        if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read)
        {
           
            perror("write");
            return 1;
        }
    }

    if (bytes_read < 0)
    {
        perror("read");
        return 1;
    }

    return 0;
 }
/*OUTPUT:
 *
 *hey
hey
what up
what up
 *
 *
 * */
