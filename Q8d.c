/**
Name:Q8d.c
Author:Pavan
Description:Program using signal system call to catch the following signal.
d. SIGALRM
Date:17th September 2024
**/
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
void sigalrm(int sig){
printf("Caught  SIGALRM, Timer expired \n");
exit(1);
}

int main(){
signal(SIGALRM,sigalrm);
alarm(5);
pause();
return 0;
}

/**
Output:Caught  SIGALRM, Timer expired 
**/

