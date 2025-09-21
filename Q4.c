#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>

int main(){
           int fd;
           const char *filename="existed_file.txt";
           fd=open(filename,O_RDWR);
	   if(fd==-1){
	   perror("FIle can't be created check if the file exists.\n");
	   return 1;
	   }
	   else{
	   printf("file opened successfully.\n");}
	   printf("\n");
	   printf("Now using open() again to see working of EXCL_flag with CREAT\n");
	   fd=open(filename,O_CREAT|O_EXCL|O_RDWR,0666);
	   if(fd==-1){
	   if(errno=EEXIST){
	   printf("Success! the file '%s' not created agaoini as it exist already because of O_EXCL flag.\n",filename);
	   }
	   else printf("Error eith O_DXCL flag.");
}
          else printf("The file does not exist so created.\n");
	  close(fd);




return 0;
}
