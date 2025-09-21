/*
 *============================================================================
Name : Q11.c
Author : Ayush Kumar
Description :Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl 
Date: 30th Aug, 2025
============================================================================
 * */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd;
    int dup_fd;
    const char *filename = "dup_test.txt";
    const char *data1 = "Hello,";
    const char *data2 = " world!";


    fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
    dup_fd = dup(fd);
    write(fd, data1, strlen(data1));
    write(dup_fd, data2, strlen(data2));

    printf("Original FD: %d\n", fd);
    printf("Duplicated FD: %d\n", dup_fd);


    close(fd);
    close(dup_fd);

    printf("\nFile updated properly. Check the content with 'cat %s'\n", filename);

    return 0;
}
/*OUTPUT:
 root@ubuntu-dev:/ss_handson# gcc Q11.c
root@ubuntu-dev:/ss_handson# ./a.out
Original FD: 3
Duplicated FD: 4

File updated properly. Check the content with 'cat dup_test.txt'
root@ubuntu-dev:/ss_handson# cat dup_test.txt
Hello, world!root@ubuntu-dev:/ss_handson# *
 *
 *
 * */
