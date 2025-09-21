/*
============================================================================
Name : Q2_b.c
Author : Ayush Kumar
Description : Create a hard link file using the `link` system call
Date: 7th Sep, 2025.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>

int main() {
    if (link("original.txt", "hard_link_linksyscall.txt") == -1) {
        printf("link failed\n");
        return 1;
    }
    printf("Hard link created successfully.\n");
    return 0;
}
/*
Hard link created successfully.
*/
