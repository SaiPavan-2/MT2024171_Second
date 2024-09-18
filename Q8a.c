/**
Name:Q8a.c
Author:Pavan
Description:Program using signal system call to catch the following signal.
a. SIGSEGV
Date:17th September 2024
**/
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
void sigsev(int sig){
printf("Caught  SIGSEV: segmentation fault occurred\n");
exit(1);
}

int main(){
signal(SIGSEGV,sigsev);
int *ptr=NULL;
*ptr=42;
return 0;
}

/**
Output:Caught  SIGSEV: segmentation fault occurred
**/
