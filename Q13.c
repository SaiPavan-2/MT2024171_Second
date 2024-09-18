/**
Name:Q13.c
Author:Pavan
Description:Program waiting to catch SIGSTOP.
Date:18th September 2024.
**/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(){
printf("PID of the process is %d \n",getpid());
for(int i=0;i<30;i++){
printf("Hello\n");
sleep(4);
}
return 0;
}
/**Output:
PID of the process is 7823 
Hello
Hello
Hello

[1]+  Stopped                 ./Q13
**/



