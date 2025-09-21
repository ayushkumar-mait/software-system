#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){

printf("Starting a infinite loop. (to stop press control +c.\n");
while(1){
printf("IN THE LOOP\n");
fflush(stdout);
sleep(1);
}
return 0;

}
