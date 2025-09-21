/*
 *============================================================================
Name : Q13.c
Author : Ayush Kumar
Description :Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select). 
Date: 1st sept, 2025
============================================================================
 * */
#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
    fd_set fds;
    struct timeval timeout;
    int ready_fds;

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for data on STDIN for 10 seconds...\n");

    ready_fds = select(STDIN_FILENO + 1, &fds, NULL, NULL, &timeout);

    if (ready_fds == -1) {

        printf("An error occurred with select().\n");
    } else if (ready_fds == 0) {
        printf("Timeout reached. No data available within 10 seconds.\n");
    } else {
        printf("Data is available! It took less than 10 seconds.\n");
    }

    return 0;
}
/*OUTPUT:
 *root@ubuntu-dev:/ss_handson# gcc Q13.c
root@ubuntu-dev:/ss_handson# ./a.out
Waiting for data on STDIN for 10 seconds...
hi there
Data is available! It took less than 10 seconds.
root@ubuntu-dev:/ss_handson# hi there
bash: hi: command not found
root@ubuntu-dev:/ss_handson# ./a.out
Waiting for data on STDIN for 10 seconds...
Timeout reached. No data available within 10 seconds.
 *
 * */
