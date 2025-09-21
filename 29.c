/*
============================================================================
Name : q29.c
Author : Ayush Kumar
Description : Write a program to get the scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
Date: 7th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int currentPolicy;
    pid_t pid;
    pid = getpid();
    currentPolicy = sched_getscheduler(pid);
    struct sched_param priority;
    priority.sched_priority = 10;

    switch (currentPolicy)
    {
    case SCHED_FIFO:
        printf("Current policy is FIFO\n");
        sched_setscheduler(pid, SCHED_RR, &priority);
        currentPolicy = sched_getscheduler(pid);
        printf("Current policy is %d\n", currentPolicy);
        break;
    case SCHED_RR:
        printf("Current policy is RR\n");
        sched_setscheduler(pid, SCHED_FIFO, &priority);
        currentPolicy = sched_getscheduler(pid);
        printf("Current policy is %d\n", currentPolicy);
        break;
    case SCHED_OTHER:
        printf("Current policy is OTHER\n");
        sched_setscheduler(pid, SCHED_RR, &priority);
        currentPolicy = sched_getscheduler(pid);
        printf("Current policy is %d\n", currentPolicy);
        break;
    default:
        perror("Error while getting current policy\n");
    }
    return 0;
}
/*OUTPUT:
 * ./a.out
Current policy is OTHER
Current policy is 0

 * 
 * */
