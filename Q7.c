/*
 *============================================================================
Name : Q7.c
Author : Ayush Kumar
Description : Write a program to copy file1 into file2 ($cp file1 file2). 
Date: 28th Aug, 2025
============================================================================
 * */
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main() {
    int source_fd, dest_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    
    source_fd = open("file1", O_RDONLY);

    
    dest_fd = open("file2", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    
    while ((bytesRead = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        write(dest_fd, buffer, bytesRead);
    }

    
    close(source_fd);
    close(dest_fd);

    return 0;
}
/*
 *OUTPUT:
 *root@ubuntu-dev:/ss_handson# vim Q7.c
root@ubuntu-dev:/ss_handson# echo "hello there!" > file1
root@ubuntu-dev:/ss_handson# gcc Q7.c
root@ubuntu-dev:/ss_handson# ./a.out
root@ubuntu-dev:/ss_handson# ls 
Q2  Q3  Q4  Q5  Q6.c  Q7.c  a.out  fifo  fifo_example.c  file1  file2  hard-link.txt  link.txt  my_pipe  rohit.txt
root@ubuntu-dev:/ss_handson# cat file2
hello there!
 * */
