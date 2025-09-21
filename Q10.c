/*
 *============================================================================
Name : Q7.c
Author : Ayush Kumar
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data. 
Date: 29th Aug, 2025
============================================================================
 * */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd;
    off_t lseek_result;
    const char *filename = "lseek_test.txt";
    const char *data1 = "AAAAAAAAAA";
    const char *data2 = "BBBBBBBBBB";

    fd = open(filename, O_RDWR | O_CREAT, 0644);


    write(fd, data1, strlen(data1));

    lseek_result = lseek(fd, 10, SEEK_CUR);

    write(fd, data2, strlen(data2));

    close(fd);

    printf("Return value of lseek: %ld\n", lseek_result);
    printf("Successfully wrote 10 bytes, then skipped 10 bytes, then wrote 10 more bytes.\n");

    return 0;
}
/*
 *
 * OUTPUT:A)
 * root@ubuntu-dev:/ss_handson# vim Q10.c
root@ubuntu-dev:/ss_handson# gcc Q10.c
root@ubuntu-dev:/ss_handson# ./a.out
Return value of lseek: 20
Successfully wrote 10 bytes, then skipped 10 bytes, then wrote 10 more bytes.
 *B)
 root@ubuntu-dev:/ss_handson# od -c lseek_test.txt
0000000   A   A   A   A   A   A   A   A   A   A  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   B   B   B   B   B   B   B   B   B   B
0000036
 *
 * */
