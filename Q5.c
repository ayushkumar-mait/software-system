#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
int main(){
int fd[5];
char filename[20];

for(int i=0;i<5;i++){
 sprintf(filename,"file'%d'.txt",i);
 fd[i]=open(filename,O_CREAT|O_RDWR,0666);

 if(fd[i]==-1){
 printf("The '%d' file can't be created.\n",i);
 }
 else printf("The '%s' succesfully created.\n",filename);

}
printf("Entering into infinite loop.\n");
while(1){
	sleep(1);
printf("hey!");}

for(int i=0;i<5;i++){
close(fd[i]);
}





return 0;}
