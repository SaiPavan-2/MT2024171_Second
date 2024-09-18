/**
Name:Q2.c
Author:Pavan
Description:Program to set (any one) system resource limit using  setrlimit system call.
Date:12th September 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void main(){

struct rlimit limit;

if(getrlimit(RLIMIT_STACK,&limit)==0){
printf("Stack size limits\n");
printf("soft limit %ld\n",limit.rlim_cur);
printf("hard limit %ld\n",limit.rlim_max);
}
limit.rlim_cur=8388600;
if(setrlimit(RLIMIT_STACK,&limit)!=0){
printf("Error in changing the value");
}
else{
printf("Displaying the new values\n");
if(getrlimit(RLIMIT_STACK,&limit)==0){
printf("Stack size limits\n");
printf("soft limit %ld\n",limit.rlim_cur);
printf("hard limit %ld\n",limit.rlim_max);
}
}

}
/*Output:
Stack size limits
soft limit 8388608
hard limit -1
Displaying the new values
Stack size limits
soft limit 8388600
hard limit -1
*/


