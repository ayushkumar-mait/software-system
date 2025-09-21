/*
 *============================================================================
Name : Q12.c
Author : Ayush Kumar
Description :Write a program to find out the opening mode of a file. Use fcntl. 
Date: 31th Aug, 2025
============================================================================
 * */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    int access_mode;
    const char *filename = argv[1];

    fd = open(filename, O_RDONLY);

    access_mode = fcntl(fd, F_GETFL);

    printf("Opening mode of file: ");

    if ((access_mode & O_ACCMODE) == O_RDONLY) {
        printf("Read Only (O_RDONLY)\n");
    } else if ((access_mode & O_ACCMODE) == O_WRONLY) {
        printf("Write Only (O_WRONLY)\n");
    } else if ((access_mode & O_ACCMODE) == O_RDWR) {
        printf("Read/Write (O_RDWR)\n");
    }

    close(fd);

    return 0;
}
/*OUTPUT:
 *root@ubuntu-dev:/ss_handson# vim Q12.c
root@ubuntu-dev:/ss_handson# gcc Q12.c
root@ubuntu-dev:/ss_handson# echo "This is the text I'm inputing" >file
root@ubuntu-dev:/ss_handson# ./a.out file
Opening mode of file: Read Only (O_RDONLY)

 *
 * */
