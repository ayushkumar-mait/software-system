/*
 *============================================================================
Name : Q8.c
Author : Ayush Kumar
Description :Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached. 
Date: 28th Aug, 2025
============================================================================
 * */

#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[256];
    const char *filename = "sample.txt";


    fp = fopen(filename, "r");


    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }


    fclose(fp);

    return 0;
}
/*OUTPUT:
 *root@ubuntu-dev:/ss_handson# touch sample.txt
root@ubuntu-dev:/ss_handson# cat > sample.txt << EOF
EOF                            
> cat > sample.txt << EOF
EOF 
> cat > sample.txt << EOF
EOF 
cat > sample.txt << EOF
EOF 

jndjknjwef3nvnojrjf
> wenffn3rjo
> EOF
root@ubuntu-dev:/ss_handson# gcc Q8.c
root@ubuntu-dev:/ss_handson# ./a.out 
EOF 
cat > sample.txt << EOF
EOF 

cat > sample.txt << EOF
EOF 
cat > sample.txt << EOF
EOF 

jndjknjwef3nvnojrjf
wenffn3rjo
 *
 *
 *
 * */
