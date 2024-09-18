/**
Name:Q8b.c
Author:Pavan
Description:Program using signal system call to catch the following signal.
b. SIGINT
Date:17th September 2024
**/
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
void sigint(int sig){
printf("Caught  SIGINT, User entered ctrl+c\n");
exit(1);
}

int main(){
signal(SIGINT,sigint);
while(1){
}
return 0;
}

/**
Output:^CCaught  SIGINT, User entered ctrl+c
**/
