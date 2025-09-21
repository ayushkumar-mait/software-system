/*
============================================================================
Name : q27.c
Author : Ayush Kumar
Description :Write a program to execute ls -Rl by the following system calls
             a. execl
             b. execlp
             c. execle
             d. execv
             e. execvp
Date: 7th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main(int argc,char *env[])
{
    char *path = "/bin/ls";
    execl(path, path, "-Rl", NULL);//a
    char *path2 = "ls";
    execlp(path2, path2, "-Rl", NULL);//b
    execle(path, path, "-Rl" ,"27c_example/",NULL, env);//c
    char *argv[] = {path,"-Rl",NULL};
    execv(path, argv);//d
    char *buf[] = {path2, "-Rl", NULL};
    execvp(path2, buf);//e     
    return 0;
}
/*./a.out
.:
total 304
-rw-r--r-- 1 root root  1539 Sep  7 14:38 1
-rw-r--r-- 1 root root  1539 Sep  7 14:38 14a.c
-rw-r--r-- 1 root root  2758 Sep  7 16:12 15.c
-rw-r--r-- 1 root root  1453 Sep  7 16:16 16a.c
-rw-r--r-- 1 root root  1432 Sep  7 16:20 16b.c
-rw-r--r-- 1 root root  1185 Sep  7 16:28 17a.c
-rw-r--r-- 1 root root  1452 Sep  7 16:26 17b.c
-rw-r--r-- 1 root root  1511 Sep  7 16:36 18a.c
-rw-r--r-- 1 root root  3443 Sep  7 16:47 18b.c
-rw-r--r-- 1 root root  1054 Sep  7 17:07 19.c
-rw-r--r-- 1 root root  1009 Sep  7 17:09 20.c
-rw-r--r-- 1 root root   671 Sep  7 17:11 21.c
-rw-r--r-- 1 root root   978 Sep  7 17:12 22.c
-rw-r--r-- 1 root root  1264 Sep  7 17:18 23.c
-rw-r--r-- 1 root root  1046 Sep  7 17:20 24.c
-rw-r--r-- 1 root root  1838 Sep  7 17:22 25.c
-rw-r--r-- 1 root root   761 Sep  7 17:57 26.c
-rw-r--r-- 1 root root   823 Sep  7 17:58 27.c
-rw-r--r-- 1 root root  1541 Sep  7 04:37 Q10.c
-rw-r--r-- 1 root root  1332 Sep  7 04:46 Q11.c
-rw-r--r-- 1 root root  1325 Sep  7 04:49 Q11b.c
-rw-r--r-- 1 root root  1357 Sep  7 04:53 Q11c.c
-rw-r--r-- 1 root root  1160 Sep  7 04:58 Q12.c
-rw-r--r-- 1 root root  1516 Sep  7 05:03 Q13.c
drwxr-xr-x 2 root root  4096 Sep  5 14:51 Q2
drwxr-xr-x 2 root root  4096 Sep  5 15:14 Q3
drwxr-xr-x 2 root root  4096 Sep  5 16:26 Q4
drwxr-xr-x 2 root root  4096 Sep  7 04:00 Q5
-rw-r--r-- 1 root root   840 Sep  7 04:08 Q6.c
-rw-r--r-- 1 root root  1152 Sep  7 04:15 Q7.c
-rw-r--r-- 1 root root  1145 Sep  7 04:22 Q8.c
-rw-r--r-- 1 root root  1977 Sep  7 04:30 Q9.c
-rwxr-xr-x 1 root root 70584 Sep  7 17:58 a.out
-rw-r--r-- 1 root root    13 Sep  7 04:49 dup2_test.txt
-rw-r--r-- 1 root root    13 Sep  7 04:52 dup_test.txt
-rwxr-xr-x 1 root root 71128 Sep  5 00:53 fifo
-rw-r--r-- 1 root root  3434 Sep  5 00:52 fifo_example.c
-rw-r--r-- 1 root root    30 Sep  7 04:58 file
-rw-r--r-- 1 root root    13 Sep  7 04:13 file1
-rw-r--r-- 1 root root    19 Sep  7 17:55 file1.txt
-rw-r--r-- 1 root root    13 Sep  7 04:13 file2
-rwxr-xr-x 1 root root 70496 Sep  7 14:33 file_type
-rw-r--r-- 1 root root     0 Sep  7 04:29 fileinfo
-rw-r--r-- 1 root root    45 Aug 28 17:05 hard-link.txt
lrwxrwxrwx 1 root root    11 Aug 28 16:46 link.txt -> orignal.txt
lrwxrwxrwx 1 root root     5 Sep  7 14:34 link_to_file -> 14a.c
-rw-r--r-- 1 root root     0 Sep  7 16:16 lock_file.txt
-rw-r--r-- 1 root root    30 Sep  7 04:35 lseek_test.txt
prw-r--r-- 1 root root     0 Aug 28 18:18 my_pipe
-rw-r--r-- 1 root root     0 Sep  7 16:19 read_file.txt
-rwxr-xr-x 1 root root 70784 Sep  7 16:41 read_lock_record
-rw-r--r-- 1 root root    72 Sep  7 16:46 records.txt
-rw-r--r-- 1 root root    48 Aug 25 17:52 rohit.txt
-rw-r--r-- 1 root root   125 Sep  7 04:20 sample.txt
-rw-r--r-- 1 root root     4 Sep  7 16:27 ticket.txt
-rwxr-xr-x 1 root root 70704 Sep  7 16:26 ticket_reserve
-rwxr-xr-x 1 root root 70536 Sep  7 16:26 ticket_set
-rw-r--r-- 1 root root   306 Sep  7 16:14 vim
-rwxr-xr-x 1 root root 70832 Sep  7 16:40 write_lock_record

./Q2:
total 20
-rwxr-xr-x 1 root root 70448 Sep  5 14:51 Q2run
-rw-r--r-- 1 root root   211 Sep  5 14:51 infiniteLoop.c

./Q3:
total 24
-rwxr-xr-x 1 root root 70440 Sep  5 15:14 Q3
-rw-r--r-- 1 root root   413 Sep  5 15:14 fd_value.c
-rw-r--r-- 1 root root    53 Sep  5 15:15 my_file_descriptor.txt

./Q4:
total 20
-rwxr-xr-x 1 root root 70584 Sep  5 16:26 Q4
-rw-r--r-- 1 root root   812 Sep  5 16:26 create_open.c
-rw-r--r-- 1 root root     0 Sep  5 15:21 existed_file.txt

./Q5:
total 20
-rwxr-xr-x 1 root root 70520 Sep  5 19:10  Q5
-rw-r--r-- 1 root root     0 Sep  7 04:00  Q6.c
-rw-r--r-- 1 root root     0 Sep  5 18:52 "file'0'.txt"
-rw-r--r-- 1 root root     0 Sep  5 18:52 "file'1'.txt"
-rw-r--r-- 1 root root     0 Sep  5 18:52 "file'2'.txt"
-rw-r--r-- 1 root root     0 Sep  5 18:52 "file'3'.txt"
-rw-r--r-- 1 root root     0 Sep  5 18:52 "file'4'.txt"
 *
 * */
