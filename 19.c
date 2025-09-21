/*
============================================================================
Name : q19.c
Author : Ayush Kumar
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 7th Sept, 2025.
============================================================================
*/

#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

int main() {
    struct timespec start_time, end_time;
    long long elapsed_nanoseconds;
    pid_t process_id;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    process_id = getpid();
    
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    elapsed_nanoseconds = (end_time.tv_sec - start_time.tv_sec) * 1000000000LL;
    elapsed_nanoseconds += (end_time.tv_nsec - start_time.tv_nsec);

    printf("The process id is: %d\n", process_id);
    printf("Difference in nano seconds is : %lld\n", elapsed_nanoseconds);

    return 0;
}

/*
Output:
The process id is: 500 
Difference in nano seconds is :2334 
*/

