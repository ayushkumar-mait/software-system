/*
 *============================================================================
Name : Q11b.c
Author : Ayush Kumar
Description :Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl 
Date: 20th Aug, 2025
============================================================================
 * */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd;
    int dup2_fd = 8;
    const char *filename = "dup2_test.txt";
    const char *data1 = "Hello,";
    const char *data2 = " world!";

    fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);

    dup2(fd, dup2_fd);

    write(fd, data1, strlen(data1));

    write(dup2_fd, data2, strlen(data2));

    printf("Original FD: %d\n", fd);
    printf("Duplicated FD: %d (Target FD)\n", dup2_fd);

    close(fd);
    close(dup2_fd);

    printf("\nFile updated properly. Check the content with 'cat %s'\n", filename);

    return 0;
}
/*OUTPUT:
 root@ubuntu-dev:/ss_handson# gcc Q11b.c
root@ubuntu-dev:/ss_handson# ./a.out
Original FD: 3
Duplicated FD: 8 (Target FD)

File updated properly. Check the content with 'cat dup2_test.txt'
root@ubuntu-dev:/ss_handson# cat dup2_test.txt*
 *
 * */
