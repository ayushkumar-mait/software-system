/*
============================================================================
Name : q30.c
Author : Ayush kumar
Description :Write a program to run a script at a specific time using a Daemon process.
Date: 7th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid > 0) {
       
        printf("Parent process exiting. The daemon is now running in the background with PID %d.\n", pid);
        exit(0);
    }

    setsid();

    time_t start_time = time(NULL);
    time_t target_time = start_time + 60; 

    while (1) {
        time_t current_time = time(NULL);
       
        if (current_time >= target_time) {
            // Execute the script
            system("./my_script.sh");
        }
       
        sleep(5);
    }

    return 0;
}
/*OUTPUT:
 * vim 30.c
root@ubuntu-dev:/ss_handson# gcc 30.c
root@ubuntu-dev:/ss_handson# vim my_script.sh
root@ubuntu-dev:/ss_handson# chmod +x my_script.sh
root@ubuntu-dev:/ss_handson# vim 30.c
root@ubuntu-dev:/ss_handson# rm 30.c\
> ^C
root@ubuntu-dev:/ss_handson# rm 30.c
root@ubuntu-dev:/ss_handson# vim 30.c
root@ubuntu-dev:/ss_handson# gcc -o daemon_executor 30.c
root@ubuntu-dev:/ss_handson# ./daemon_executor
Parent process exiting. The daemon is now running in the background with PID 614.
root@ubuntu-dev:/ss_handson# touch daemon_log.txt
root@ubuntu-dev:/ss_handson# ps aux | grep daemon_executor
kill 614
root       614  0.0  0.0   2120   580 ?        Ss   18:15   0:00 ./daemon_executor
root       638  0.0  0.0   3124  1640 pts/1    S+   18:17   0:00 grep --color=auto daemon_executor
root@ubuntu-dev:/ss_handson#
 * */
