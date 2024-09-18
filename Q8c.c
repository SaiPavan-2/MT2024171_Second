/**
Name:Q8c.c
Author:Pavan
Description:Program using signal system call to catch the following signal.
c. SIGFPE
Date:17th September 2024
**/
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
void sigfpe(int sig){
printf("Caught  SIGFPE, Division by zero error\n");
exit(1);
}

int main(){
signal(SIGFPE,sigfpe);
int n=0;
printf("%d",5/n);
return 0;
}

/**
Output:Caught  SIGFPE, Division by zero error
**/
