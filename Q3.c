#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>

#define FILE_NAME "my_file_descriptor.txt";
int main(){
 int fd;
 const char* name =FILE_NAME;
 fd=creat(name,0666);
 if(fd==-1){
 perror("Error creating the file.\n");
 return 1;
 }
printf("The file created by the name of: ' %s'\n",name);
printf("The file descriptor value is :'%d'\n ",fd);
close(fd);





return 0;
}
