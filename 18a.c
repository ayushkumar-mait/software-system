/*
 *============================================================================
Name : Q18a.c
Author : Ayush Kumar
Description : Write a program to perform Record locking.
a. Implement write lock 
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

    fd = open("records.txt", O_RDWR);

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (record_num - 1) * sizeof(struct record);
    lock.l_len = sizeof(struct record);
    lock.l_pid = getpid();

    printf("Attempting to get a write lock on record %d...\n", record_num);
    fcntl(fd, F_SETLKW, &lock);
    printf("Write lock acquired on record %d.\n", record_num);

    lseek(fd, (record_num - 1) * sizeof(struct record), SEEK_SET);
    read(fd, &rec, sizeof(struct record));

    printf("Record ID before update: %d\n", rec.id);
    rec.id++;
    lseek(fd, (record_num - 1) * sizeof(struct record), SEEK_SET);
    write(fd, &rec, sizeof(struct record));
    printf("Record ID updated to: %d. Press Enter to release lock.\n", rec.id);

    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("Lock released. Exiting.\n");

    close(fd);
    return 0;
}
/*OUTPUT:
 * scenario1:
 *
 *
*/
