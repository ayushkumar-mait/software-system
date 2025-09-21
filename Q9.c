/*
 *============================================================================
Name : Q9.c
Author : Ayush Kumar
Description :Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change 
Date: 7th sept, 2025
============================================================================
 * */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {

    struct stat file_info;

    stat(argv[1], &file_info);


    printf("File Information for: %s\n", argv[1]);
    printf("-----------------------------------\n");
    printf("a. Inode number: %ld\n", (long)file_info.st_ino);
    printf("b. Number of hard links: %ld\n", (long)file_info.st_nlink);
    printf("c. UID: %d\n", file_info.st_uid);
    printf("d. GID: %d\n", file_info.st_gid);
    printf("e. Size (in bytes): %lld\n", (long long)file_info.st_size);
    printf("f. Block size (I/O): %ld\n", (long)file_info.st_blksize);
    printf("g. Number of blocks: %lld\n", (long long)file_info.st_blocks);
    printf("h. Time of last access: %s", ctime(&file_info.st_atime));
    printf("i. Time of last modification: %s", ctime(&file_info.st_mtime));
    printf("j. Time of last change: %s", ctime(&file_info.st_ctime));

    return 0;
}

/*OUTPUT:
 * root@ubuntu-dev:/ss_handson# vim Q9.c
root@ubuntu-dev:/ss_handson# touch fileinfo
root@ubuntu-dev:/ss_handson# gcc Q9.c
root@ubuntu-dev:/ss_handson# ./a.out fileinfo
File Information for: fileinfo
-----------------------------------
a. Inode number: 3672
b. Number of hard links: 1
c. UID: 0
d. GID: 0
e. Size (in bytes): 0
f. Block size (I/O): 4096
g. Number of blocks: 0
h. Time of last access: Sun Sep  7 04:29:05 2025
i. Time of last modification: Sun Sep  7 04:29:05 2025
j. Time of last change: Sun Sep  7 04:29:05 2025
 *
 *
 * */
