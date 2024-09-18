/**
Name:Q2.c
Author:Pavan
Description:Program to print the system resource limits using getrlimit system call.
Date:12th September 2024
**/
#include <sys/resource.h>
#include <stdlib.h>
#include <stdio.h>

void print_resource(int resource,const char* msg){
struct rlimit limit;
if(getrlimit(resource,&limit)==0){
printf("%s limits \n",msg);
printf("soft limit %ld\n",(long)limit.rlim_cur);
printf("hard limit %ld\n",(long)limit.rlim_max);
}
else{
perror("error");
exit(1);
}
}
void main(){
print_resource(RLIMIT_AS,"Max size of process virtual mem");
print_resource(RLIMIT_CORE,"Core file size");
print_resource(RLIMIT_CPU,"Amount of cpu time process may consume");
print_resource(RLIMIT_DATA,"size of process data seg");
print_resource(RLIMIT_FSIZE,"file size");
print_resource(RLIMIT_LOCKS,"limit of locks");
print_resource(RLIMIT_MEMLOCK,"Number of bytes of mem that may be locked into Ram");
print_resource(RLIMIT_MSGQUEUE,"POSIX message  Queue size");
print_resource(RLIMIT_STACK,"Stack size");
}
/*Output:
*/



