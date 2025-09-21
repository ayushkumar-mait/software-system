/*
 *============================================================================
Name : Q18b.c
Author : Ayush Kumar
Description :Write a program to perform Record locking.
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition. 
Date: 7th sept, 2025
============================================================================
 * */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct record {
    int id;
    char name[20];
};

int main(int argc, char *argv[]) {
    struct record rec;
    struct flock lock;
    int fd;
    int record_num = atoi(argv[1]);

    fd = open("records.txt", O_RDONLY);

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (record_num - 1) * sizeof(struct record);
    lock.l_len = sizeof(struct record);
    lock.l_pid = getpid();

    printf("Attempting to get a read lock on record %d...\n", record_num);
    fcntl(fd, F_SETLKW, &lock);
    printf("Read lock acquired on record %d. Press Enter to release lock.\n", record_num);

    lseek(fd, (record_num - 1) * sizeof(struct record), SEEK_SET);
    read(fd, &rec, sizeof(struct record));

    printf("Record ID: %d\n", rec.id);
    printf("Record Name: %s\n", rec.name);

    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("Lock released. Exiting.\n");

    close(fd);
    return 0;
}
/*PUTPUT:
 * Scenario1:
 root@ubuntu-dev:/ss_handson# rm 18b.c
root@ubuntu-dev:/ss_handson# vim 18b.c
root@ubuntu-dev:/ss_handson# echo -ne "\x01\x00\x00\x00Record 1           \x02\x00\x00\x00Record 2           \x03\x00\x00\x00Record 3           " > records.txt
root@ubuntu-dev:/ss_handson# gcc -o write_lock_record 18a.c               
root@ubuntu-dev:/ss_handson# gcc -o read_lock_record 18b.c             
root@ubuntu-dev:/ss_handson# ./write_lock_record 1
Attempting to get a write lock on record 1...
Write lock acquired on record 1.
Record ID before update: 1
Record ID updated to: 2. Press Enter to release lock.

Lock released. Exiting.*
in terminal2::
root@ubuntu-dev:/ss_handson# ./read_lock_record 1
Attempting to get a read lock on record 1...

Read lock acquired on record 1. Press Enter to release lock.
Record ID: 2
Record Name: Record 1           
Lock released. Exiting.
root@ubuntu-dev:/ss_handson#

SCENARIO  2:
in terminal 2:
root@ubuntu-dev:/ss_handson# ./write_lock_record 2
Attempting to get a write lock on record 2...
Write lock acquired on record 2.
Record ID before update: 1375731712
Record ID updated to: 1375731713. Press Enter to release lock.

Lock released. Exiting.
root@ubuntu-dev:/ss_handson#
in terminal 1:
root@ubuntu-dev:/ss_handson# ./write_lock_record 2
Attempting to get a write lock on record 2...

Write lock acquired on record 2.
Record ID before update: 1375731713
Record ID updated to: 1375731714. Press Enter to release lock.
Lock released. Exiting.
SSENARIO 3:
root@ubuntu-dev:/ss_handson# ./read_lock_record 3
Attempting to get a read lock on record 3...
Read lock acquired on record 3. Press Enter to release lock.
Record ID: 1699872768
Record Name: cord 3           ?
root@ubuntu-dev:/ss_handson# ./write_lock_record 3
Attempting to get a write lock on record 3...

Write lock acquired on record 3.
Record ID before update: 1699872768
Record ID updated to: 1699872769. Press Enter to release lock.
Lock released. Exiting.
  
 * */
